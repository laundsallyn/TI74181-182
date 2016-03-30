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
    temp00 = ~(temp0|temp1|temp2) & 0x1;
    temp01 = ~(temp3|temp4) & 0x1;

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
    temp002 = temp00 & notm;
    temp003 = notm & in.cin_ & temp01;

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
    temp014 = temp01 & temp03 & temp05 & temp07;
    temp015 = in.cin_ & temp01 & temp03 & temp05 & temp07;
    temp016 = temp00 & temp03 & temp05 & temp07;
    temp017 = temp02 & temp05 & temp07;
    temp018 = temp04 & temp07;
    temp019 = temp06;

    temp0001 = (~(temp003|temp002)) & 0x1;
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


struct cl_182_in {
  int cin_;   // carry input
  int g0_;    // generate input
  int g1_;
  int g2_;
  int g3_;
  int p0_;    // propagate input
  int p1_;
  int p2_;
  int p3_;
}cl_182_in;

struct cl_182_out {
  int cn0_;   // carry group 1
  int cn1_;   // carry group 2
  int cn2_;   // carry group 3
  int g_;     // generate
  int p_;     // propagate
}cl_182_out;

struct cl_182_out ti74812(struct cl_182_in in){
  struct cl_182_out out;
  int temp00, temp01, temp02, temp03, temp04, temp05, temp06, temp07,
  temp08, temp09, temp10, temp11, temp12, temp13, temp000, temp001,
  temp002,temp003;

  temp00 = in.g0_ & in.p0_;
  temp01 = in.g0_ &  in.cin_;
  temp02 = in.g1_ & in.p1_;
  temp03 = in.g0_ & in.g1_ & in.p0_;
  temp04 = in.cin_ & in.g0_ & in.g1_;
  temp05 = in.g2_ & in.p2_;
  temp06 = in.p1_ & in.g1_ & in.g2_;
  temp07 = in.p0_ & in.g0_ & in.g1_ & in.g2_;
  temp08 = in.cin_ & in.g0_ & in.g1_ & in.g2_;
  temp09 = in.p3_ & in.g3_;
  temp10 = in.p2_ & in.g3_ & in.g2_;
  temp11 = in.p1_ & in.g1_ & in.g2_ & in.g3_;
  temp12 = in.g3_ & in.g2_ & in.g1_ & in.g0_;
  temp13 = in.p3_ & in.p2_ & in.p1_ & in.p0_;
  temp000 = !(temp00|temp01);
  temp001 = !(temp02|temp03|temp04);
  temp002 = !(temp05|temp06|temp07|temp08);
  temp003 = (temp09|temp10|temp11|temp12);

  out.p_ = temp13;
  out.g_ = temp003;
  out.cn2_ = temp002;
  out.cn1_ = temp001;
  out.cn0_ = temp000;

  return out;
}

 // 16-bit input/output structures

struct alu_16_in {
  int cin;              // carry input
                        // 16-bit, a-vector input
  int a00,a01,a02,a03,a04,a05,a06,a07,a08,a09,a10,a11,a12,a13,a14,a15;    
                        // 16-bit, b-vector input
  int b00,b01,b02,b03,b04,b05,b06,b07,b08,b09,b10,b11,b12,b13,b14,b15;
  int m;                // logical or arithmetic
  int s0,s1,s2,s3;      // function select

};

struct alu_16_out {
  int f00,f01,f02,f03,f04,f05,f06,f07,f08,f09,f10,f11,f12,f13,f14,f15;    // 16-bit, output vector
  int cout;   // output carry
};

struct alu_16_out sixteen_bit_alu (struct alu_16_in input){
  struct alu_16_out out;
  struct cl_181_in in[4];
  in[0].a0 = input.a00;
  in[0].a1 = input.a01;
  in[0].a2 = input.a02;
  in[0].a3 = input.a03;
  in[0].b0 = input.b00;
  in[0].b1 = input.b01;
  in[0].b2 = input.b02;
  in[0].b3 = input.b03;
  in[0].cin_= (~input.cin) & 0x1;

  in[1].a0 = input.a04;
  in[1].a1 = input.a05;
  in[1].a2 = input.a06;
  in[1].a3 = input.a07;
  in[1].b0 = input.b04;
  in[1].b1 = input.b05;
  in[1].b2 = input.b06;
  in[1].b3 = input.b07;
  in[1].cin_= 1;

  in[2].a0 = input.a08;
  in[2].a1 = input.a09;
  in[2].a2 = input.a10;
  in[2].a3 = input.a11;
  in[2].b0 = input.b08;
  in[2].b1 = input.b09;
  in[2].b2 = input.b10;
  in[2].b3 = input.b11;
  in[2].cin_= 1;

  in[3].a0 = input.a12;
  in[3].a1 = input.a13;
  in[3].a2 = input.a14;
  in[3].a3 = input.a15;
  in[3].b0 = input.b12;
  in[3].b1 = input.b13;
  in[3].b2 = input.b14;
  in[3].b3 = input.b15;
  in[3].cin_= 1;

  int i;
  for (i = 0; i < 4; i++){ 
    in[i].m = input.m;
    in[i].s0 = input.s0;
    in[i].s1 = input.s1;
    in[i].s2 = input.s2;
    in[i].s3 = input.s3;
  }
  
  struct cl_182_in carry;
  struct cl_181_out r0,r1,r2,r3; 
  r0 = ti74181 (in[0]);
  r1 = ti74181 (in[1]);
  r2 = ti74181 (in[2]);
  r3 = ti74181 (in[3]);
  printf("r0.cout is %d\n", r0.cout_);
  carry.cin_ = (~input.cin) & 0x1;
  carry.p0_ = r0.p_;
  carry.g0_ = r0.g_;
  carry.p1_ = r1.p_;
  carry.g1_ = r1.g_;
  carry.p2_ = r2.p_;
  carry.g2_ = r2.g_;
  carry.p3_ = r3.p_;
  carry.g3_ = r3.g_;
  printf("r0.g_ is %d r0.p_ is %d\n", r0.g_, r0.p_);
  printf("r1.g_ is %d r1.p_ is %d\n", r1.g_, r1.p_);
  printf("r2.g_ is %d r2.p_ is %d\n", r2.g_, r2.p_);
  printf("r3.g_ is %d r3.p_ is %d\n", r3.g_, r3.p_);

  struct cl_182_out co = ti74812(carry);
  in[1].cin_ = co.cn0_;
  in[2].cin_ = co.cn1_;
  in[3].cin_ = co.cn2_;
  printf("cn0_  is %d\n", co.cn0_);
  printf("cn1_  is %d\n", co.cn1_);
  printf("cn2_  is %d\n", co.cn2_);

  //printf("in[%d].cin_ is %d\nin[%d].cin_ is %d\nin[%d].cin_ is %d\n",1, co.cn0_,2, co.cn1_,3, co.cn2_);
  r0 = ti74181 (in[0]);
  r1 = ti74181 (in[1]);
  r2 = ti74181 (in[2]);
  r3 = ti74181 (in[3]);
  out.cout = (!r3.cout_) | (!co.g_);
  out.f00 = r0.f0;
  out.f01 = r0.f1;
  out.f02 = r0.f2;
  out.f03 = r0.f3;
  out.f04 = r1.f0;
  out.f05 = r1.f1;
  out.f06 = r1.f2;
  out.f07 = r1.f3; 
  out.f08 = r2.f0;
  out.f09 = r2.f1;
  out.f10 = r2.f2;
  out.f11 = r2.f3;
  out.f12 = r3.f0;
  out.f13 = r3.f1;
  out.f14 = r3.f2;
  out.f15 = r3.f3; 
  return out;
}

int main (){
  struct alu_16_in in = {1,
                         1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,  
                         1,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,
                         0, 
                         1,0,0,1};
  struct alu_16_out res = sixteen_bit_alu (in);
  printf("ans is %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", res.f00,res.f01,res.f02,res.f03,res.f04,res.f05,res.f06,res.f07,res.f08,res.f09,res.f10,res.f11,res.f12,res.f13,res.f14,res.f15);


}