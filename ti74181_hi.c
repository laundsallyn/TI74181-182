#include <stdio.h>
struct cl_181_in {
  int cin_;   // carry input
  int a0;     // a-vector input
  int a1;
  int a2;
  int a3;
  int b0;     // b-vector input
  int b1;
  int b2;
  int b3;
  int m;      // logical or arithmetic
  int s0;     // function select
  int s1;
  int s2;
  int s3;
};

struct cl_181_out {
  int f0;     // function output
  int f1;
  int f2;
  int f3;
  int cout_;  // carry output
  int a_equal_b;
  int p_;     // propagate
  int g_;     // generate
};
struct cl_181_out ti74181(struct cl_181_in input){
    struct cl_181_out out = {0,0,0,0,0,0,0,0};
    struct cl_181_in in = input;
    in.cin_ = (~(input.cin_)) & 0x1;
    int temp0,temp1,temp2,temp3,temp4,temp00,temp01,temp02,temp03,temp04,temp05,temp06,temp07,temp00003,temp00004;
    int temp000,temp001,temp002,temp003,temp004,temp005,temp006,temp007,temp008,temp009,temp010,temp011,temp012,temp013,temp014,temp015;
    int temp016,temp017,temp018,temp019,temp0000,temp0001,temp0002,temp0003,temp0004,temp00000,temp00001,temp00002;
    int notm = (~in.m) & 0x1;
    temp0 = in.a0;
    temp1 = in.b0 & in.s0;
    temp2 = (~in.b0) & in.s1;
    temp3 = (~in.b0) & in.s2 & in.a0;
    temp4 = in.s3 & in.b0 & in.a0;
    printf("temp3 is %d, temp4 is %d\n", temp3, temp4);
    temp00 = ~(temp0|temp1|temp2) & 0x1;
    temp01 = ~(temp3|temp4) & 0x1;
    printf("temp00 is %d, temp01 is %d\n", temp00, temp01);

    temp0 = in.a1;
    temp1 = in.b1 & in.s0;
    temp2 = (~in.b1) & in.s1;
    temp3 = (~in.b1) & in.s2 & in.a1;
    temp4 = in.s3 & in.b1 & in.a1;
    temp02 = ~(temp0|temp1|temp2) & 0x1;
    temp03 = ~(temp3|temp4) & 0x1;

    temp0 = in.a2;
    temp1 = in.b2 & in.s0;
    temp2 = (~in.b2) & in.s1;
    temp3 = (~in.b2) & in.s2 & in.a2;
    temp4 = in.s3 & in.b2 & in.a2;
    temp04 = ~(temp0|temp1|temp2) & 0x1;
    temp05 = ~(temp3|temp4) & 0x1;
    
    temp0 = in.a3;
    temp1 = in.b3 & in.s0;
    temp2 = (~in.b3) & in.s1;
    temp3 = (~in.b3) & in.s2 & in.a3;
    temp4 = in.s3 & in.b3 & in.a3;
    temp06 = ~(temp0|temp1|temp2) & 0x1;
    temp07 = ~(temp3|temp4) & 0x1;

    temp000 =  ~(notm & in.cin_) & 0x1;
    temp001 = (~(temp00 & temp01)) & (temp00 | temp01);
    printf(" temp001 is %d\n", temp001);

    temp002 = temp00 & notm;
    temp003 = notm & in.cin_ & temp01;
    printf("temp002 is %d, temp003 is %d\n", temp002, temp003);

    temp004 = (~(temp02 & temp03)) & (temp02 | temp03);
    temp005 = temp02 & notm;
    temp006 = temp03 & temp00 & notm;
    temp007 = notm & in.cin_ & temp01 & temp03;

    temp008 = (~(temp04 & temp05)) & (temp04 | temp05);
    temp009 = notm & temp04;
    temp010 = notm & temp02 & temp05;
    temp011 = notm & temp00 & temp03 & temp05;
    temp012 = notm & in.cin_ & temp03 & temp05;

    temp013 = (~(temp06 & temp07)) & (temp06 | temp07);
    temp014 = (~(temp01 & temp03 & temp05 & temp07))&0x1;
    temp015 = (~(in.cin_ & temp01 & temp03 & temp05 & temp07))&0x1;
    temp016 = temp00 & temp03 & temp05 & temp07;
    temp017 = temp02 & temp05 & temp07;
    temp018 = temp04 & temp07;
    temp019 = temp06;

    temp0001 = (~(temp003|temp002)) & 0x1;
    printf(" temp0001 is %d\n", temp0001);

    temp0002 = (~(temp005|temp006|temp007)) & 0x1;
    temp0003 = (~(temp009|temp010|temp011|temp012)) & 0x1;
    temp0004 = (~(temp016|temp017|temp018|temp019)) & 0x1;

    temp00000 = (~(temp000 & temp001)) & (temp000 | temp001);
    
    temp00001 = (~(temp004 & temp0001)) & (temp004 | temp0001); 
    temp00002 = (~(temp008 & temp0002)) & (temp008 | temp0002);
    temp00003 = (~(temp013 & temp0003)) & (temp013 | temp0003);
    temp00004 = ((~temp015)|(~temp0004)) & 0x1;

    out.g_ = temp0004;
    out.cout_ = temp00004;
    out.p_ = temp014;
    out.f3 = temp00003;
    out.f2 = temp00002;
    out.f1 = temp00001;
    out.f0 = temp00000;
    out.a_equal_b = temp00000 & temp00001 & temp00002 & temp00003;
    return out;
}

int main (){


  int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;

  //                    cin_,a0,a1,a2,a3,b0,b1,b2,b3, m,s0,s1,s2,s3
  struct cl_181_in in = { 0,  1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1};
  struct cl_181_out out = ti74181(in);
  printf("answer is %d%d%d%d  %d%d%d\n", out.f3,out.f2,out.f1,out.f0, out.cout_, out.p_, out.g_);


}


  // int i,j,k,l;
  // for (i = 0; i < 2; i++){
  //   for (j = 0; j < 2; j++){
  //     for (k = 0; k < 2; k++){
  //       for (l = 0; l < 2; l++){
  //         struct cl_181_in in = {0,l,k,j,i,0,0,0,1,0,0,0,0,0};
  //         printf("input  is %d%d%d%d\n", i,j,k,l);
  //         struct cl_181_out out = ti74181(in);
  //         printf("answer is %d%d%d%d\n", out.f3,out.f2,out.f1,out.f0);
  //       }
  //     }
  //   }
  // }

