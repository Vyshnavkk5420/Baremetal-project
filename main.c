/*DOC
NAME: VYSHNAV K K 
DATE: 10/10/24
DESCRIPTION: Baremetal assignment
DOC*/

#include<stdio.h>
typedef struct
{
    float i,j,k;
}vector;

vector create_vector(float i,float j,float k)
{
    vector v = {i,j,k};
    return v;
}

vector complement(vector v)
{
    vector n = {-(v.i),-(v.j),-(v.k)};
    return n;
}

typedef struct 
{
    float s;
    vector v;
}quaternion;

quaternion quat(float s,float i,float j,float k)
{
    quaternion q = {s,create_vector(i,j,k)};
    return q;
}

quaternion complement_quat(quaternion q)
{
    quaternion q_bar = {q.s,complement(q.v)};
    return q_bar;
}

float dot_quat(quaternion q,quaternion q_bar)
{
    float dot = (q.s * q_bar.s) + ((q.v.i) * (q_bar.v.i)) + ((q.v.j) * (q_bar.v.j)) + ((q.v.k) * (q_bar.v.k));
    return dot;
}

quaternion mult_quat(quaternion q,quaternion q_bar)
{
    float s,a,b,c;
    s = (q.s * q_bar.s) - ((q.v.i) * (q_bar.v.i)) - ((q.v.j) * (q_bar.v.j)) - ((q.v.k) * (q_bar.v.k));
    a = (q.s * (q_bar.v.i)) + ((q.v.i) * q_bar.s) + ((q.v.j) * (q_bar.v.k)) - ((q.v.k) * ( q_bar.v.j));
    b = (q.s * (q_bar.v.j)) + ((q.v.j) * q_bar.s) + ((q.v.k) * (q_bar.v.i)) - ((q.v.i) * ( q_bar.v.k));
    c = (q.s * (q_bar.v.k)) + ((q.v.k) * q_bar.s) + ((q.v.i) * (q_bar.v.j)) - ((q.v.j) * ( q_bar.v.i));
    quaternion res = {s,create_vector(a,b,c)};
    return res;
}

int main()
{
    quaternion q,q_bar,a;
    q = quat(0,1,1,1);
    q_bar = complement_quat(q);
    a = mult_quat(q,q_bar);
    float b = dot_quat(q,q_bar);

    return 0;
}


