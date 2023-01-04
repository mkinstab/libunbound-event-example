#include <event2/event.h>
#include <unbound.h>
#include <unbound-event.h>
#include <stdio.h>

struct _query {
    struct event_base* base;
    struct ub_ctx* ctx;
    int async_id;
};

static void _callback(void* mydata, int rcode, void* packet, int packet_len, int sec, char* why_bogus, int was_ratelimited)
{
    printf("rcode:%d len:%d sec:%d\n", rcode, packet_len, sec);
}

static void _timeout(evutil_socket_t fd, short event, void *arg)
{
    struct _query* q = (struct _query*)arg;

    printf("timeout %d\n", q->async_id);
    ub_cancel(q->ctx, q->async_id);
    event_base_loopbreak(q->base);
}

int main(void)
{
    struct event_base* base = event_base_new();
    struct ub_ctx* ctx = ub_ctx_create_event(base);
    struct event* timeout;
    struct timeval tv;
    struct _query q;

    int async_id = 0;
    ub_resolve_event(ctx, "thawte.cn", 1, 1, 0, _callback, &async_id);
    printf("id:%d\n", async_id);

    q.base = base;
    q.ctx = ctx;
    q.async_id = async_id;
    timeout = evtimer_new(base, _timeout, (void*)&q);
    evutil_timerclear(&tv);
    tv.tv_sec = 1;
    evtimer_add(timeout, &tv);

    event_base_dispatch(base);

    return 0;
}