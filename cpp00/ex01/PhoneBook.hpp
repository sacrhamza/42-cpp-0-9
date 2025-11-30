#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP



class PhoneBook
{
  private:
    Contact m_contacts[8];
    int m_currentIndex;
    bool m_full;
    void save_contact(Contact& new_contact);
  public:
    static void get_data(std::string& r_field, std::string message);
    void add_contact(void);
    void search_contacts();
    void print(void);
    PhoneBook(void);
};
#endif
