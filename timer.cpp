
#include "timer.hpp"

Timer :: Timer()
: m_start_time(0), m_total_time(0), m_running(0)
{}

Timer :: ~Timer()
{}

long int Timer :: m_time() const
{
    timeb tb;
    ftime( &tb );
    const int ncount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return ncount;
}

long int Timer :: m_span(long int start) const
{
    long int span = m_time() - start;
    if ( span < 0 ) 
        span += 0x100000 * 1000;
    return span;
}


void Timer :: start()
{
    if (!m_running) {
        m_start_time = m_time();
        m_running = 1;
    }
}

void Timer :: stop()
{
    if (m_running) {
        m_total_time += m_span(m_start_time);
        m_running = 0;
    }
}

double Timer :: getTime()
{
    long int t;
    if (m_running) {
        t = m_total_time + m_span(m_start_time);
    } else {
        t = m_total_time;
    }
    return ((double) t) / 1000;

}

void Timer :: reset()
{
    m_running = 0;
    m_start_time = 0;
    m_total_time = 0;
}

