#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <string>

class Warlock
{
    public:
        Warlock(std::string name, std::string title);
        void                setTitle(std::string const &title);
        std::string const   &getTitle() const;
        std::string const   &getName() const;
		~Warlock();
		void				introduce() const;
    private:
        Warlock(void);
        Warlock(Warlock const &rhs);
        Warlock &operator=(Warlock const &rhs);
        std::string  _name;
        std::string  _title;
};

#endif