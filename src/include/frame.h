#ifndef _FRAME_H_
#define _FRAME_H_

#include <stdint.h>

typedef enum {
    FRAME_TRANS,
    FRAME_BOARDCAST,
    FRAME_HEARTBEAT,
    FRAME_AUTH,
} frame_type;

struct frame_hdr {
    uint32_t dst;
    uint32_t src;
    
    uint8_t ack:1,
            enc:1,
            ext:1,
            type:5;
    
    uint8_t channel;
};

struct frame_heartbeat {
    struct frame_hdr hdr;
    uint32_t timestamp;
};

struct frame_trans {
    struct frame_hdr hdr;
    uint16_t frame_size;

    uint32_t seq_prev;
    uint32_t seq_next;
    uint32_t seq;
    
    void *data[];    
};

struct frame_trans_extern {
    struct frame_hdr hdr;
    uint16_t frame_size;

    uint64_t seq_prev;
    uint64_t seq_next;
    uint64_t seq;
    
    void *data[];
};


struct frame_auth {
    struct frame_hdr hdr;
    uint16_t frame_size;

};

#endif