#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct p_name_type {
	p_name_type(string n) : type("String") {
		name = n;
	}
	p_name_type(string n, string t) {
		name = n;
		type = t;
	}
	string name;
	string type;
};

// get the property type.
string get_type(string * input) {
	if (input == nullptr)
		return "String";

	string type_prefix(""), type_suffix(""), t, l;

	auto list_find_pos = (*input).find("_");
	t = (*input).substr(0, list_find_pos);
	l = (*input).substr(list_find_pos == string::npos ? 0 : list_find_pos);

	if (t != l && ( l == "_l" || l == "_l" || l == "_List")) {
		type_prefix = "List<";
		type_suffix = ">";
	}

	if (t == "" || t == "-s" || t == "-string" || t == "-String") {
		t = "String";
	}
	else if (t == "-b" || t == "-boolean" || t == "-Boolean") {
		t = "Boolean";
	} 
	else if (t == "-i" || t == "-int" || t == "-Integer") {
		t = "Integer";
	}
	else if (t == "-d" || t == "-double" || t == "-Double") {
		t = "Double";
	}
	else {
		t = t.substr(1);
	}
	return type_prefix + t + type_suffix;
}

vector<p_name_type> parse_args(vector<string> a) {
	decltype(a.size()) i = 0;
	vector<p_name_type> v_p_name_type;
	while(i < a.size()) {
		auto c_a = a[i];
		string * n_a = nullptr;
		if (i + 1 < a.size() && (a[i + 1][0] == '-' || a[i + 1][0] == '_')) {
			n_a = &a[++i];
		}
		p_name_type p(c_a, get_type(n_a));
		v_p_name_type.push_back(p);	
		i++;	
	}
	return v_p_name_type;
}

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		cerr<<"Need more arguments!"<<endl;
		return 1;
	}
	string class_name (argv[1]);
	vector<string> vp;
	for (int i = 2; i < argc; i++) {
		vp.push_back(argv[i]);	
	}

	auto interim_result = parse_args(vp);
	class_name[0] = toupper(class_name[0]);
	string file_name = class_name + ".java";
	ofstream f(file_name);
	f << "/**\n";
	f << " * The bean class for " << class_name << "\n";
	f << " */\n";
	f << "public class " << class_name << " {\n";
	for (decltype(vp.size()) i = 0; i < interim_result.size(); i++) {
		auto & p = interim_result[i];
		f << "    /**\n";
		f << "     * Get " << p.name << ".\n";
		f << "     *\n";
		f << "     * @return the " << p.name << "\n";
		f << "     */\n";
		p.name[0] = toupper(p.name[0]);
		f << "    public " << p.type << " get" << p.name << "() {\n";
		p.name[0] = tolower(p.name[0]);
		f << "        return "<< p.name <<";\n";
		f << "    }\n";
		f << "\n";
		f << "    /**\n";
		f << "     * Set " << p.name << ".\n";
		f << "     *\n";
		f << "     * @param " << p.name << " the " << p.name <<"\n";
		f << "     */\n";
		p.name[0] = toupper(p.name[0]);
		f << "    public void set" << p.name;
		p.name[0] = tolower(p.name[0]);
		f << "(final " << p.type << " " << p.name << ") {\n";
		f << "        this."<< p.name << " = " << p.name << ";\n";
		f << "    }\n";
		f << "\n";
	}

	for (auto p : interim_result) {
		f << "    /** The " << p.name << ".*/\n";
		f << "    private " << p.type << " " << p.name << ";\n";
	}
	f << "}\n";

	f.close();
	return 0;
}

