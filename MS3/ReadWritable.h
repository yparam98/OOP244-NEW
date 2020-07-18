#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

namespace sdds
{
    class ReadWritable
    {
        private:
            bool comma_seperate{false};
        public:
            ReadWritable();
            ~ReadWritable();

            bool isCsv() const;
            void setCsv(bool);

    };
}

#endif // SDDS_READWRITABLE_H