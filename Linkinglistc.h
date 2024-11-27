typedef struct DualWayNode DualWay;

typedef enum {
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    UNKNOWN
} DataType;



struct DualWayNode{
    DataType datatype;
    void * value;
    DualWay *pre;
    DualWay *next;
};
