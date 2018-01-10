/**
 * The bean class for Test
 */
public class Test {
    /**
     * Get names.
     *
     * @return the names
     */
    public List<String> getNames() {
        return names;
    }

    /**
     * Set names.
     *
     * @param names the names
     */
    public void setNames(final List<String> names) {
        this.names = names;
    }

    /**
     * Get date.
     *
     * @return the date
     */
    public String getDate() {
        return date;
    }

    /**
     * Set date.
     *
     * @param date the date
     */
    public void setDate(final String date) {
        this.date = date;
    }

    /**
     * Get setting.
     *
     * @return the setting
     */
    public Setting getSetting() {
        return setting;
    }

    /**
     * Set setting.
     *
     * @param setting the setting
     */
    public void setSetting(final Setting setting) {
        this.setting = setting;
    }

    /** The names.*/
    private List<String> names;
    /** The date.*/
    private String date;
    /** The setting.*/
    private Setting setting;
}
