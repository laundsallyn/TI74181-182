#include <stdio.h>
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

int main (){

  int a,b,c,d,e,f,g,h,i;
  for(a = 0; a<2; a++){
    for(b = 0; b<2; b++){ 
      for(c = 0; c<2; c++){
        for(d = 0; d<2; d++){
        //  for(e = 0; e<2; e++){
            for(f = 0; f<2; f++){
              for(g = 0; g<2; g++){
                for(h = 0; h<2; h++){
                  for(i = 0; i<2; i++){
                    struct cl_182_in in = {a,b,c,d,0,f,g,h,i};
                    printf("Input is %d%d%d%d%d%d%d%d%d\n", in.cin_,in.g0_, in.g1_, in.g2_,
                     in.g3_, in.p0_, in.p1_, in.p2_, in.p3_);

                    struct cl_182_out res = ti74812(in);
                    printf("The result is %d %d %d %d %d\n",res.cn0_,res.cn1_,res.cn2_,res.g_,res.p_);
                  }
                }
              }
            }
     //     }
        }
      }
    }
  }

}