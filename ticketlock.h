struct ticketlock {
int ticket;
int turn;
};

struct rwlock{
    struct ticketlock mutex,rw_mutex;
    int count;
};
