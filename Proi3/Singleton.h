#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
    public:
        static Singleton& getInstance()
        {
            static S instance;
            return instance;
        }
        Singleton();
        virtual ~Singleton();
    protected:
    private:
};

#endif // SINGLETON_H
