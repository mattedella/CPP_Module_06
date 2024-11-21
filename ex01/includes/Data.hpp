
#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class Data {

    private:
        int _data;
    
    public:
        Data(void);
        Data(const Data& copy);

        int getData(void) const;
        void setData(int num);

        ~Data(void);
};

#endif