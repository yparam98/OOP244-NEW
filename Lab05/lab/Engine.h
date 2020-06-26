#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
    const int TYPE_MAX_SIZE{30};

    class Engine
    {
    private:
        double m_size{0.0};
        char m_type[TYPE_MAX_SIZE];

    public:
        Engine();
        Engine(const char *, double);

        double get() const;
        void display() const;
    };
} // namespace sdds

#endif // SDDS_ENGINE_H