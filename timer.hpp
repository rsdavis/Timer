
#include <sys/timeb.h>

class Timer
{
    private:

        long int m_start_time;
        long int m_total_time;
        bool m_running;

        long int m_time() const;
        long int m_span(long int) const;

    public:
        
        Timer();
        ~Timer();

        void start();
        void stop();
        void reset();
        double getTime();
};
