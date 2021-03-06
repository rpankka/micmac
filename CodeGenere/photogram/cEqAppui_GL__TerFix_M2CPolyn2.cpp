// File Automatically generated by eLiSe
#include "general/all.h"
#include "private/all.h"
#include "cEqAppui_GL__TerFix_M2CPolyn2.h"


cEqAppui_GL__TerFix_M2CPolyn2::cEqAppui_GL__TerFix_M2CPolyn2():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,9));
   AddIntRef (cIncIntervale("Orient",9,15));
   Close(false);
}



void cEqAppui_GL__TerFix_M2CPolyn2::ComputeVal()
{
   double tmp0_ = mCompCoord[9];
   double tmp1_ = mCompCoord[10];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = cos(tmp0_);
   double tmp4_ = tmp3_*tmp2_;
   double tmp5_ = sin(tmp0_);
   double tmp6_ = tmp5_*tmp2_;
   double tmp7_ = sin(tmp1_);
   double tmp8_ = mCompCoord[11];
   double tmp9_ = sin(tmp8_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp7_);
   double tmp12_ = cos(tmp8_);
   double tmp13_ = mCompCoord[12];
   double tmp14_ = mLocXTer-tmp13_;
   double tmp15_ = -(tmp5_);
   double tmp16_ = tmp15_*tmp10_;
   double tmp17_ = tmp3_*tmp11_;
   double tmp18_ = tmp17_*tmp12_;
   double tmp19_ = tmp16_+tmp18_;
   double tmp20_ = tmp3_*tmp10_;
   double tmp21_ = tmp5_*tmp11_;
   double tmp22_ = tmp21_*tmp12_;
   double tmp23_ = tmp20_+tmp22_;
   double tmp24_ = tmp2_*tmp12_;
   double tmp25_ = mCompCoord[13];
   double tmp26_ = mLocYTer-tmp25_;
   double tmp27_ = mCompCoord[14];
   double tmp28_ = mLocZTer-tmp27_;
   double tmp29_ = tmp15_*tmp12_;
   double tmp30_ = tmp17_*tmp9_;
   double tmp31_ = tmp29_+tmp30_;
   double tmp32_ = tmp3_*tmp12_;
   double tmp33_ = tmp21_*tmp9_;
   double tmp34_ = tmp32_+tmp33_;
   double tmp35_ = tmp2_*tmp9_;
   double tmp36_ = mCompCoord[0];
   double tmp37_ = (tmp19_)*mLocGL_0_0;
   double tmp38_ = (tmp23_)*mLocGL_1_0;
   double tmp39_ = tmp37_+tmp38_;
   double tmp40_ = tmp24_*mLocGL_2_0;
   double tmp41_ = tmp39_+tmp40_;
   double tmp42_ = (tmp41_)*(tmp14_);
   double tmp43_ = (tmp19_)*mLocGL_0_1;
   double tmp44_ = (tmp23_)*mLocGL_1_1;
   double tmp45_ = tmp43_+tmp44_;
   double tmp46_ = tmp24_*mLocGL_2_1;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = (tmp47_)*(tmp26_);
   double tmp49_ = tmp42_+tmp48_;
   double tmp50_ = (tmp19_)*mLocGL_0_2;
   double tmp51_ = (tmp23_)*mLocGL_1_2;
   double tmp52_ = tmp50_+tmp51_;
   double tmp53_ = tmp24_*mLocGL_2_2;
   double tmp54_ = tmp52_+tmp53_;
   double tmp55_ = (tmp54_)*(tmp28_);
   double tmp56_ = tmp49_+tmp55_;
   double tmp57_ = tmp36_/(tmp56_);
   double tmp58_ = tmp4_*mLocGL_0_0;
   double tmp59_ = tmp6_*mLocGL_1_0;
   double tmp60_ = tmp58_+tmp59_;
   double tmp61_ = tmp7_*mLocGL_2_0;
   double tmp62_ = tmp60_+tmp61_;
   double tmp63_ = (tmp62_)*(tmp14_);
   double tmp64_ = tmp4_*mLocGL_0_1;
   double tmp65_ = tmp6_*mLocGL_1_1;
   double tmp66_ = tmp64_+tmp65_;
   double tmp67_ = tmp7_*mLocGL_2_1;
   double tmp68_ = tmp66_+tmp67_;
   double tmp69_ = (tmp68_)*(tmp26_);
   double tmp70_ = tmp63_+tmp69_;
   double tmp71_ = tmp4_*mLocGL_0_2;
   double tmp72_ = tmp6_*mLocGL_1_2;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = tmp7_*mLocGL_2_2;
   double tmp75_ = tmp73_+tmp74_;
   double tmp76_ = (tmp75_)*(tmp28_);
   double tmp77_ = tmp70_+tmp76_;
   double tmp78_ = (tmp77_)*(tmp57_);
   double tmp79_ = mCompCoord[1];
   double tmp80_ = tmp78_+tmp79_;
   double tmp81_ = (tmp80_)-mLocPolyn2_State_1_0;
   double tmp82_ = (tmp81_)/mLocPolyn2_State_0_0;
   double tmp83_ = (tmp31_)*mLocGL_0_0;
   double tmp84_ = (tmp34_)*mLocGL_1_0;
   double tmp85_ = tmp83_+tmp84_;
   double tmp86_ = tmp35_*mLocGL_2_0;
   double tmp87_ = tmp85_+tmp86_;
   double tmp88_ = (tmp87_)*(tmp14_);
   double tmp89_ = (tmp31_)*mLocGL_0_1;
   double tmp90_ = (tmp34_)*mLocGL_1_1;
   double tmp91_ = tmp89_+tmp90_;
   double tmp92_ = tmp35_*mLocGL_2_1;
   double tmp93_ = tmp91_+tmp92_;
   double tmp94_ = (tmp93_)*(tmp26_);
   double tmp95_ = tmp88_+tmp94_;
   double tmp96_ = (tmp31_)*mLocGL_0_2;
   double tmp97_ = (tmp34_)*mLocGL_1_2;
   double tmp98_ = tmp96_+tmp97_;
   double tmp99_ = tmp35_*mLocGL_2_2;
   double tmp100_ = tmp98_+tmp99_;
   double tmp101_ = (tmp100_)*(tmp28_);
   double tmp102_ = tmp95_+tmp101_;
   double tmp103_ = (tmp102_)*(tmp57_);
   double tmp104_ = mCompCoord[2];
   double tmp105_ = tmp103_+tmp104_;
   double tmp106_ = (tmp105_)-mLocPolyn2_State_2_0;
   double tmp107_ = (tmp106_)/mLocPolyn2_State_0_0;
   double tmp108_ = mCompCoord[3];
   double tmp109_ = mCompCoord[4];
   double tmp110_ = mCompCoord[5];
   double tmp111_ = (tmp82_)*(tmp107_);
   double tmp112_ = mCompCoord[6];
   double tmp113_ = (tmp107_)*(tmp107_);
   double tmp114_ = (tmp82_)*(tmp82_);

  mVal[0] = ((mLocPolyn2_State_1_0+(((1+tmp108_)*(tmp82_)+tmp109_*(tmp107_))-tmp110_*2*tmp114_+tmp112_*tmp111_+mCompCoord[7]*tmp113_)*mLocPolyn2_State_0_0)-mLocXIm)*mLocScNorm;

  mVal[1] = ((mLocPolyn2_State_2_0+(((1-tmp108_)*(tmp107_)+tmp109_*(tmp82_)+tmp110_*tmp111_)-tmp112_*2*tmp113_+mCompCoord[8]*tmp114_)*mLocPolyn2_State_0_0)-mLocYIm)*mLocScNorm;

}


void cEqAppui_GL__TerFix_M2CPolyn2::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[9];
   double tmp1_ = mCompCoord[10];
   double tmp2_ = cos(tmp1_);
   double tmp3_ = cos(tmp0_);
   double tmp4_ = tmp3_*tmp2_;
   double tmp5_ = sin(tmp0_);
   double tmp6_ = tmp5_*tmp2_;
   double tmp7_ = sin(tmp1_);
   double tmp8_ = mCompCoord[11];
   double tmp9_ = sin(tmp8_);
   double tmp10_ = -(tmp9_);
   double tmp11_ = -(tmp7_);
   double tmp12_ = cos(tmp8_);
   double tmp13_ = mCompCoord[12];
   double tmp14_ = mLocXTer-tmp13_;
   double tmp15_ = -(tmp5_);
   double tmp16_ = tmp15_*tmp10_;
   double tmp17_ = tmp3_*tmp11_;
   double tmp18_ = tmp17_*tmp12_;
   double tmp19_ = tmp16_+tmp18_;
   double tmp20_ = tmp3_*tmp10_;
   double tmp21_ = tmp5_*tmp11_;
   double tmp22_ = tmp21_*tmp12_;
   double tmp23_ = tmp20_+tmp22_;
   double tmp24_ = tmp2_*tmp12_;
   double tmp25_ = mCompCoord[13];
   double tmp26_ = mLocYTer-tmp25_;
   double tmp27_ = mCompCoord[14];
   double tmp28_ = mLocZTer-tmp27_;
   double tmp29_ = tmp15_*tmp12_;
   double tmp30_ = tmp17_*tmp9_;
   double tmp31_ = tmp29_+tmp30_;
   double tmp32_ = tmp3_*tmp12_;
   double tmp33_ = tmp21_*tmp9_;
   double tmp34_ = tmp32_+tmp33_;
   double tmp35_ = tmp2_*tmp9_;
   double tmp36_ = mCompCoord[0];
   double tmp37_ = (tmp19_)*mLocGL_0_0;
   double tmp38_ = (tmp23_)*mLocGL_1_0;
   double tmp39_ = tmp37_+tmp38_;
   double tmp40_ = tmp24_*mLocGL_2_0;
   double tmp41_ = tmp39_+tmp40_;
   double tmp42_ = (tmp41_)*(tmp14_);
   double tmp43_ = (tmp19_)*mLocGL_0_1;
   double tmp44_ = (tmp23_)*mLocGL_1_1;
   double tmp45_ = tmp43_+tmp44_;
   double tmp46_ = tmp24_*mLocGL_2_1;
   double tmp47_ = tmp45_+tmp46_;
   double tmp48_ = (tmp47_)*(tmp26_);
   double tmp49_ = tmp42_+tmp48_;
   double tmp50_ = (tmp19_)*mLocGL_0_2;
   double tmp51_ = (tmp23_)*mLocGL_1_2;
   double tmp52_ = tmp50_+tmp51_;
   double tmp53_ = tmp24_*mLocGL_2_2;
   double tmp54_ = tmp52_+tmp53_;
   double tmp55_ = (tmp54_)*(tmp28_);
   double tmp56_ = tmp49_+tmp55_;
   double tmp57_ = tmp36_/(tmp56_);
   double tmp58_ = tmp4_*mLocGL_0_0;
   double tmp59_ = tmp6_*mLocGL_1_0;
   double tmp60_ = tmp58_+tmp59_;
   double tmp61_ = tmp7_*mLocGL_2_0;
   double tmp62_ = tmp60_+tmp61_;
   double tmp63_ = (tmp62_)*(tmp14_);
   double tmp64_ = tmp4_*mLocGL_0_1;
   double tmp65_ = tmp6_*mLocGL_1_1;
   double tmp66_ = tmp64_+tmp65_;
   double tmp67_ = tmp7_*mLocGL_2_1;
   double tmp68_ = tmp66_+tmp67_;
   double tmp69_ = (tmp68_)*(tmp26_);
   double tmp70_ = tmp63_+tmp69_;
   double tmp71_ = tmp4_*mLocGL_0_2;
   double tmp72_ = tmp6_*mLocGL_1_2;
   double tmp73_ = tmp71_+tmp72_;
   double tmp74_ = tmp7_*mLocGL_2_2;
   double tmp75_ = tmp73_+tmp74_;
   double tmp76_ = (tmp75_)*(tmp28_);
   double tmp77_ = tmp70_+tmp76_;
   double tmp78_ = (tmp77_)*(tmp57_);
   double tmp79_ = mCompCoord[1];
   double tmp80_ = tmp78_+tmp79_;
   double tmp81_ = (tmp80_)-mLocPolyn2_State_1_0;
   double tmp82_ = (tmp81_)/mLocPolyn2_State_0_0;
   double tmp83_ = (tmp31_)*mLocGL_0_0;
   double tmp84_ = (tmp34_)*mLocGL_1_0;
   double tmp85_ = tmp83_+tmp84_;
   double tmp86_ = tmp35_*mLocGL_2_0;
   double tmp87_ = tmp85_+tmp86_;
   double tmp88_ = (tmp87_)*(tmp14_);
   double tmp89_ = (tmp31_)*mLocGL_0_1;
   double tmp90_ = (tmp34_)*mLocGL_1_1;
   double tmp91_ = tmp89_+tmp90_;
   double tmp92_ = tmp35_*mLocGL_2_1;
   double tmp93_ = tmp91_+tmp92_;
   double tmp94_ = (tmp93_)*(tmp26_);
   double tmp95_ = tmp88_+tmp94_;
   double tmp96_ = (tmp31_)*mLocGL_0_2;
   double tmp97_ = (tmp34_)*mLocGL_1_2;
   double tmp98_ = tmp96_+tmp97_;
   double tmp99_ = tmp35_*mLocGL_2_2;
   double tmp100_ = tmp98_+tmp99_;
   double tmp101_ = (tmp100_)*(tmp28_);
   double tmp102_ = tmp95_+tmp101_;
   double tmp103_ = (tmp102_)*(tmp57_);
   double tmp104_ = mCompCoord[2];
   double tmp105_ = tmp103_+tmp104_;
   double tmp106_ = (tmp105_)-mLocPolyn2_State_2_0;
   double tmp107_ = (tmp106_)/mLocPolyn2_State_0_0;
   double tmp108_ = mCompCoord[3];
   double tmp109_ = 1+tmp108_;
   double tmp110_ = ElSquare(tmp56_);
   double tmp111_ = (tmp56_)/tmp110_;
   double tmp112_ = ElSquare(mLocPolyn2_State_0_0);
   double tmp113_ = mCompCoord[4];
   double tmp114_ = (tmp111_)*(tmp77_);
   double tmp115_ = tmp114_*mLocPolyn2_State_0_0;
   double tmp116_ = (tmp115_)/tmp112_;
   double tmp117_ = (tmp116_)*(tmp82_);
   double tmp118_ = mCompCoord[5];
   double tmp119_ = tmp118_*2;
   double tmp120_ = (tmp111_)*(tmp102_);
   double tmp121_ = tmp120_*mLocPolyn2_State_0_0;
   double tmp122_ = (tmp121_)/tmp112_;
   double tmp123_ = mCompCoord[6];
   double tmp124_ = (tmp122_)*(tmp107_);
   double tmp125_ = mCompCoord[7];
   double tmp126_ = mLocPolyn2_State_0_0/tmp112_;
   double tmp127_ = (tmp126_)*(tmp82_);
   double tmp128_ = (tmp126_)*(tmp107_);
   double tmp129_ = (tmp82_)*(tmp82_);
   double tmp130_ = (tmp82_)*(tmp107_);
   double tmp131_ = (tmp107_)*(tmp107_);
   double tmp132_ = -(1);
   double tmp133_ = tmp132_*tmp5_;
   double tmp134_ = tmp133_*tmp2_;
   double tmp135_ = -(tmp3_);
   double tmp136_ = tmp135_*tmp10_;
   double tmp137_ = tmp133_*tmp11_;
   double tmp138_ = tmp137_*tmp12_;
   double tmp139_ = tmp136_+tmp138_;
   double tmp140_ = tmp133_*tmp10_;
   double tmp141_ = tmp140_+tmp18_;
   double tmp142_ = tmp135_*tmp12_;
   double tmp143_ = tmp137_*tmp9_;
   double tmp144_ = tmp142_+tmp143_;
   double tmp145_ = tmp133_*tmp12_;
   double tmp146_ = tmp145_+tmp30_;
   double tmp147_ = (tmp139_)*mLocGL_0_0;
   double tmp148_ = (tmp141_)*mLocGL_1_0;
   double tmp149_ = tmp147_+tmp148_;
   double tmp150_ = (tmp149_)*(tmp14_);
   double tmp151_ = (tmp139_)*mLocGL_0_1;
   double tmp152_ = (tmp141_)*mLocGL_1_1;
   double tmp153_ = tmp151_+tmp152_;
   double tmp154_ = (tmp153_)*(tmp26_);
   double tmp155_ = tmp150_+tmp154_;
   double tmp156_ = (tmp139_)*mLocGL_0_2;
   double tmp157_ = (tmp141_)*mLocGL_1_2;
   double tmp158_ = tmp156_+tmp157_;
   double tmp159_ = (tmp158_)*(tmp28_);
   double tmp160_ = tmp155_+tmp159_;
   double tmp161_ = tmp36_*(tmp160_);
   double tmp162_ = -(tmp161_);
   double tmp163_ = tmp162_/tmp110_;
   double tmp164_ = tmp134_*mLocGL_0_0;
   double tmp165_ = tmp4_*mLocGL_1_0;
   double tmp166_ = tmp164_+tmp165_;
   double tmp167_ = (tmp166_)*(tmp14_);
   double tmp168_ = tmp134_*mLocGL_0_1;
   double tmp169_ = tmp4_*mLocGL_1_1;
   double tmp170_ = tmp168_+tmp169_;
   double tmp171_ = (tmp170_)*(tmp26_);
   double tmp172_ = tmp167_+tmp171_;
   double tmp173_ = tmp134_*mLocGL_0_2;
   double tmp174_ = tmp4_*mLocGL_1_2;
   double tmp175_ = tmp173_+tmp174_;
   double tmp176_ = (tmp175_)*(tmp28_);
   double tmp177_ = tmp172_+tmp176_;
   double tmp178_ = (tmp177_)*(tmp57_);
   double tmp179_ = (tmp163_)*(tmp77_);
   double tmp180_ = tmp178_+tmp179_;
   double tmp181_ = (tmp180_)*mLocPolyn2_State_0_0;
   double tmp182_ = (tmp181_)/tmp112_;
   double tmp183_ = (tmp182_)*(tmp82_);
   double tmp184_ = (tmp144_)*mLocGL_0_0;
   double tmp185_ = (tmp146_)*mLocGL_1_0;
   double tmp186_ = tmp184_+tmp185_;
   double tmp187_ = (tmp186_)*(tmp14_);
   double tmp188_ = (tmp144_)*mLocGL_0_1;
   double tmp189_ = (tmp146_)*mLocGL_1_1;
   double tmp190_ = tmp188_+tmp189_;
   double tmp191_ = (tmp190_)*(tmp26_);
   double tmp192_ = tmp187_+tmp191_;
   double tmp193_ = (tmp144_)*mLocGL_0_2;
   double tmp194_ = (tmp146_)*mLocGL_1_2;
   double tmp195_ = tmp193_+tmp194_;
   double tmp196_ = (tmp195_)*(tmp28_);
   double tmp197_ = tmp192_+tmp196_;
   double tmp198_ = (tmp197_)*(tmp57_);
   double tmp199_ = (tmp163_)*(tmp102_);
   double tmp200_ = tmp198_+tmp199_;
   double tmp201_ = (tmp200_)*mLocPolyn2_State_0_0;
   double tmp202_ = (tmp201_)/tmp112_;
   double tmp203_ = (tmp202_)*(tmp107_);
   double tmp204_ = tmp132_*tmp7_;
   double tmp205_ = tmp204_*tmp3_;
   double tmp206_ = tmp204_*tmp5_;
   double tmp207_ = -(tmp2_);
   double tmp208_ = tmp207_*tmp3_;
   double tmp209_ = tmp208_*tmp12_;
   double tmp210_ = tmp207_*tmp5_;
   double tmp211_ = tmp210_*tmp12_;
   double tmp212_ = tmp204_*tmp12_;
   double tmp213_ = tmp208_*tmp9_;
   double tmp214_ = tmp210_*tmp9_;
   double tmp215_ = tmp204_*tmp9_;
   double tmp216_ = tmp209_*mLocGL_0_0;
   double tmp217_ = tmp211_*mLocGL_1_0;
   double tmp218_ = tmp216_+tmp217_;
   double tmp219_ = tmp212_*mLocGL_2_0;
   double tmp220_ = tmp218_+tmp219_;
   double tmp221_ = (tmp220_)*(tmp14_);
   double tmp222_ = tmp209_*mLocGL_0_1;
   double tmp223_ = tmp211_*mLocGL_1_1;
   double tmp224_ = tmp222_+tmp223_;
   double tmp225_ = tmp212_*mLocGL_2_1;
   double tmp226_ = tmp224_+tmp225_;
   double tmp227_ = (tmp226_)*(tmp26_);
   double tmp228_ = tmp221_+tmp227_;
   double tmp229_ = tmp209_*mLocGL_0_2;
   double tmp230_ = tmp211_*mLocGL_1_2;
   double tmp231_ = tmp229_+tmp230_;
   double tmp232_ = tmp212_*mLocGL_2_2;
   double tmp233_ = tmp231_+tmp232_;
   double tmp234_ = (tmp233_)*(tmp28_);
   double tmp235_ = tmp228_+tmp234_;
   double tmp236_ = tmp36_*(tmp235_);
   double tmp237_ = -(tmp236_);
   double tmp238_ = tmp237_/tmp110_;
   double tmp239_ = tmp205_*mLocGL_0_0;
   double tmp240_ = tmp206_*mLocGL_1_0;
   double tmp241_ = tmp239_+tmp240_;
   double tmp242_ = tmp2_*mLocGL_2_0;
   double tmp243_ = tmp241_+tmp242_;
   double tmp244_ = (tmp243_)*(tmp14_);
   double tmp245_ = tmp205_*mLocGL_0_1;
   double tmp246_ = tmp206_*mLocGL_1_1;
   double tmp247_ = tmp245_+tmp246_;
   double tmp248_ = tmp2_*mLocGL_2_1;
   double tmp249_ = tmp247_+tmp248_;
   double tmp250_ = (tmp249_)*(tmp26_);
   double tmp251_ = tmp244_+tmp250_;
   double tmp252_ = tmp205_*mLocGL_0_2;
   double tmp253_ = tmp206_*mLocGL_1_2;
   double tmp254_ = tmp252_+tmp253_;
   double tmp255_ = tmp2_*mLocGL_2_2;
   double tmp256_ = tmp254_+tmp255_;
   double tmp257_ = (tmp256_)*(tmp28_);
   double tmp258_ = tmp251_+tmp257_;
   double tmp259_ = (tmp258_)*(tmp57_);
   double tmp260_ = (tmp238_)*(tmp77_);
   double tmp261_ = tmp259_+tmp260_;
   double tmp262_ = (tmp261_)*mLocPolyn2_State_0_0;
   double tmp263_ = (tmp262_)/tmp112_;
   double tmp264_ = (tmp263_)*(tmp82_);
   double tmp265_ = tmp213_*mLocGL_0_0;
   double tmp266_ = tmp214_*mLocGL_1_0;
   double tmp267_ = tmp265_+tmp266_;
   double tmp268_ = tmp215_*mLocGL_2_0;
   double tmp269_ = tmp267_+tmp268_;
   double tmp270_ = (tmp269_)*(tmp14_);
   double tmp271_ = tmp213_*mLocGL_0_1;
   double tmp272_ = tmp214_*mLocGL_1_1;
   double tmp273_ = tmp271_+tmp272_;
   double tmp274_ = tmp215_*mLocGL_2_1;
   double tmp275_ = tmp273_+tmp274_;
   double tmp276_ = (tmp275_)*(tmp26_);
   double tmp277_ = tmp270_+tmp276_;
   double tmp278_ = tmp213_*mLocGL_0_2;
   double tmp279_ = tmp214_*mLocGL_1_2;
   double tmp280_ = tmp278_+tmp279_;
   double tmp281_ = tmp215_*mLocGL_2_2;
   double tmp282_ = tmp280_+tmp281_;
   double tmp283_ = (tmp282_)*(tmp28_);
   double tmp284_ = tmp277_+tmp283_;
   double tmp285_ = (tmp284_)*(tmp57_);
   double tmp286_ = (tmp238_)*(tmp102_);
   double tmp287_ = tmp285_+tmp286_;
   double tmp288_ = (tmp287_)*mLocPolyn2_State_0_0;
   double tmp289_ = (tmp288_)/tmp112_;
   double tmp290_ = (tmp289_)*(tmp107_);
   double tmp291_ = -(tmp12_);
   double tmp292_ = tmp132_*tmp9_;
   double tmp293_ = tmp291_*tmp15_;
   double tmp294_ = tmp292_*tmp17_;
   double tmp295_ = tmp293_+tmp294_;
   double tmp296_ = tmp291_*tmp3_;
   double tmp297_ = tmp292_*tmp21_;
   double tmp298_ = tmp296_+tmp297_;
   double tmp299_ = tmp292_*tmp2_;
   double tmp300_ = tmp292_*tmp15_;
   double tmp301_ = tmp12_*tmp17_;
   double tmp302_ = tmp300_+tmp301_;
   double tmp303_ = tmp292_*tmp3_;
   double tmp304_ = tmp12_*tmp21_;
   double tmp305_ = tmp303_+tmp304_;
   double tmp306_ = tmp12_*tmp2_;
   double tmp307_ = (tmp295_)*mLocGL_0_0;
   double tmp308_ = (tmp298_)*mLocGL_1_0;
   double tmp309_ = tmp307_+tmp308_;
   double tmp310_ = tmp299_*mLocGL_2_0;
   double tmp311_ = tmp309_+tmp310_;
   double tmp312_ = (tmp311_)*(tmp14_);
   double tmp313_ = (tmp295_)*mLocGL_0_1;
   double tmp314_ = (tmp298_)*mLocGL_1_1;
   double tmp315_ = tmp313_+tmp314_;
   double tmp316_ = tmp299_*mLocGL_2_1;
   double tmp317_ = tmp315_+tmp316_;
   double tmp318_ = (tmp317_)*(tmp26_);
   double tmp319_ = tmp312_+tmp318_;
   double tmp320_ = (tmp295_)*mLocGL_0_2;
   double tmp321_ = (tmp298_)*mLocGL_1_2;
   double tmp322_ = tmp320_+tmp321_;
   double tmp323_ = tmp299_*mLocGL_2_2;
   double tmp324_ = tmp322_+tmp323_;
   double tmp325_ = (tmp324_)*(tmp28_);
   double tmp326_ = tmp319_+tmp325_;
   double tmp327_ = tmp36_*(tmp326_);
   double tmp328_ = -(tmp327_);
   double tmp329_ = tmp328_/tmp110_;
   double tmp330_ = (tmp329_)*(tmp77_);
   double tmp331_ = tmp330_*mLocPolyn2_State_0_0;
   double tmp332_ = (tmp331_)/tmp112_;
   double tmp333_ = (tmp332_)*(tmp82_);
   double tmp334_ = (tmp302_)*mLocGL_0_0;
   double tmp335_ = (tmp305_)*mLocGL_1_0;
   double tmp336_ = tmp334_+tmp335_;
   double tmp337_ = tmp306_*mLocGL_2_0;
   double tmp338_ = tmp336_+tmp337_;
   double tmp339_ = (tmp338_)*(tmp14_);
   double tmp340_ = (tmp302_)*mLocGL_0_1;
   double tmp341_ = (tmp305_)*mLocGL_1_1;
   double tmp342_ = tmp340_+tmp341_;
   double tmp343_ = tmp306_*mLocGL_2_1;
   double tmp344_ = tmp342_+tmp343_;
   double tmp345_ = (tmp344_)*(tmp26_);
   double tmp346_ = tmp339_+tmp345_;
   double tmp347_ = (tmp302_)*mLocGL_0_2;
   double tmp348_ = (tmp305_)*mLocGL_1_2;
   double tmp349_ = tmp347_+tmp348_;
   double tmp350_ = tmp306_*mLocGL_2_2;
   double tmp351_ = tmp349_+tmp350_;
   double tmp352_ = (tmp351_)*(tmp28_);
   double tmp353_ = tmp346_+tmp352_;
   double tmp354_ = (tmp353_)*(tmp57_);
   double tmp355_ = (tmp329_)*(tmp102_);
   double tmp356_ = tmp354_+tmp355_;
   double tmp357_ = (tmp356_)*mLocPolyn2_State_0_0;
   double tmp358_ = (tmp357_)/tmp112_;
   double tmp359_ = (tmp358_)*(tmp107_);
   double tmp360_ = tmp132_*(tmp41_);
   double tmp361_ = tmp36_*tmp360_;
   double tmp362_ = -(tmp361_);
   double tmp363_ = tmp362_/tmp110_;
   double tmp364_ = tmp132_*(tmp62_);
   double tmp365_ = tmp364_*(tmp57_);
   double tmp366_ = (tmp363_)*(tmp77_);
   double tmp367_ = tmp365_+tmp366_;
   double tmp368_ = (tmp367_)*mLocPolyn2_State_0_0;
   double tmp369_ = (tmp368_)/tmp112_;
   double tmp370_ = (tmp369_)*(tmp82_);
   double tmp371_ = tmp132_*(tmp87_);
   double tmp372_ = tmp371_*(tmp57_);
   double tmp373_ = (tmp363_)*(tmp102_);
   double tmp374_ = tmp372_+tmp373_;
   double tmp375_ = (tmp374_)*mLocPolyn2_State_0_0;
   double tmp376_ = (tmp375_)/tmp112_;
   double tmp377_ = (tmp376_)*(tmp107_);
   double tmp378_ = tmp132_*(tmp47_);
   double tmp379_ = tmp36_*tmp378_;
   double tmp380_ = -(tmp379_);
   double tmp381_ = tmp380_/tmp110_;
   double tmp382_ = tmp132_*(tmp68_);
   double tmp383_ = tmp382_*(tmp57_);
   double tmp384_ = (tmp381_)*(tmp77_);
   double tmp385_ = tmp383_+tmp384_;
   double tmp386_ = (tmp385_)*mLocPolyn2_State_0_0;
   double tmp387_ = (tmp386_)/tmp112_;
   double tmp388_ = (tmp387_)*(tmp82_);
   double tmp389_ = tmp132_*(tmp93_);
   double tmp390_ = tmp389_*(tmp57_);
   double tmp391_ = (tmp381_)*(tmp102_);
   double tmp392_ = tmp390_+tmp391_;
   double tmp393_ = (tmp392_)*mLocPolyn2_State_0_0;
   double tmp394_ = (tmp393_)/tmp112_;
   double tmp395_ = (tmp394_)*(tmp107_);
   double tmp396_ = tmp132_*(tmp54_);
   double tmp397_ = tmp36_*tmp396_;
   double tmp398_ = -(tmp397_);
   double tmp399_ = tmp398_/tmp110_;
   double tmp400_ = tmp132_*(tmp75_);
   double tmp401_ = tmp400_*(tmp57_);
   double tmp402_ = (tmp399_)*(tmp77_);
   double tmp403_ = tmp401_+tmp402_;
   double tmp404_ = (tmp403_)*mLocPolyn2_State_0_0;
   double tmp405_ = (tmp404_)/tmp112_;
   double tmp406_ = (tmp405_)*(tmp82_);
   double tmp407_ = tmp132_*(tmp100_);
   double tmp408_ = tmp407_*(tmp57_);
   double tmp409_ = (tmp399_)*(tmp102_);
   double tmp410_ = tmp408_+tmp409_;
   double tmp411_ = (tmp410_)*mLocPolyn2_State_0_0;
   double tmp412_ = (tmp411_)/tmp112_;
   double tmp413_ = (tmp412_)*(tmp107_);
   double tmp414_ = 1-tmp108_;
   double tmp415_ = (tmp116_)*(tmp107_);
   double tmp416_ = (tmp122_)*(tmp82_);
   double tmp417_ = tmp415_+tmp416_;
   double tmp418_ = tmp124_+tmp124_;
   double tmp419_ = tmp123_*2;
   double tmp420_ = tmp117_+tmp117_;
   double tmp421_ = mCompCoord[8];
   double tmp422_ = (tmp126_)*tmp113_;
   double tmp423_ = tmp127_+tmp127_;
   double tmp424_ = tmp128_+tmp128_;
   double tmp425_ = (tmp82_)*mLocPolyn2_State_0_0;
   double tmp426_ = tmp425_*mLocScNorm;
   double tmp427_ = tmp130_*mLocPolyn2_State_0_0;
   double tmp428_ = tmp427_*mLocScNorm;
   double tmp429_ = (tmp182_)*(tmp107_);
   double tmp430_ = (tmp202_)*(tmp82_);
   double tmp431_ = tmp429_+tmp430_;
   double tmp432_ = tmp203_+tmp203_;
   double tmp433_ = tmp183_+tmp183_;
   double tmp434_ = (tmp263_)*(tmp107_);
   double tmp435_ = (tmp289_)*(tmp82_);
   double tmp436_ = tmp434_+tmp435_;
   double tmp437_ = tmp290_+tmp290_;
   double tmp438_ = tmp264_+tmp264_;
   double tmp439_ = (tmp332_)*(tmp107_);
   double tmp440_ = (tmp358_)*(tmp82_);
   double tmp441_ = tmp439_+tmp440_;
   double tmp442_ = tmp359_+tmp359_;
   double tmp443_ = tmp333_+tmp333_;
   double tmp444_ = (tmp369_)*(tmp107_);
   double tmp445_ = (tmp376_)*(tmp82_);
   double tmp446_ = tmp444_+tmp445_;
   double tmp447_ = tmp377_+tmp377_;
   double tmp448_ = tmp370_+tmp370_;
   double tmp449_ = (tmp387_)*(tmp107_);
   double tmp450_ = (tmp394_)*(tmp82_);
   double tmp451_ = tmp449_+tmp450_;
   double tmp452_ = tmp395_+tmp395_;
   double tmp453_ = tmp388_+tmp388_;
   double tmp454_ = (tmp405_)*(tmp107_);
   double tmp455_ = (tmp412_)*(tmp82_);
   double tmp456_ = tmp454_+tmp455_;
   double tmp457_ = tmp413_+tmp413_;
   double tmp458_ = tmp406_+tmp406_;

  mVal[0] = ((mLocPolyn2_State_1_0+(((tmp109_)*(tmp82_)+tmp113_*(tmp107_))-tmp119_*tmp129_+tmp123_*tmp130_+tmp125_*tmp131_)*mLocPolyn2_State_0_0)-mLocXIm)*mLocScNorm;

  mCompDer[0][0] = (((tmp116_)*(tmp109_)+(tmp122_)*tmp113_)-(tmp420_)*tmp119_+(tmp417_)*tmp123_+(tmp418_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][1] = ((tmp126_)*(tmp109_)-(tmp423_)*tmp119_+tmp128_*tmp123_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][2] = (tmp422_+tmp127_*tmp123_+(tmp424_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][3] = tmp426_;
  mCompDer[0][4] = (tmp107_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][5] = -(2*tmp129_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][6] = tmp428_;
  mCompDer[0][7] = tmp131_*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][8] = 0;
  mCompDer[0][9] = (((tmp182_)*(tmp109_)+(tmp202_)*tmp113_)-(tmp433_)*tmp119_+(tmp431_)*tmp123_+(tmp432_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][10] = (((tmp263_)*(tmp109_)+(tmp289_)*tmp113_)-(tmp438_)*tmp119_+(tmp436_)*tmp123_+(tmp437_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][11] = (((tmp332_)*(tmp109_)+(tmp358_)*tmp113_)-(tmp443_)*tmp119_+(tmp441_)*tmp123_+(tmp442_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][12] = (((tmp369_)*(tmp109_)+(tmp376_)*tmp113_)-(tmp448_)*tmp119_+(tmp446_)*tmp123_+(tmp447_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][13] = (((tmp387_)*(tmp109_)+(tmp394_)*tmp113_)-(tmp453_)*tmp119_+(tmp451_)*tmp123_+(tmp452_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[0][14] = (((tmp405_)*(tmp109_)+(tmp412_)*tmp113_)-(tmp458_)*tmp119_+(tmp456_)*tmp123_+(tmp457_)*tmp125_)*mLocPolyn2_State_0_0*mLocScNorm;
  mVal[1] = ((mLocPolyn2_State_2_0+(((tmp414_)*(tmp107_)+tmp113_*(tmp82_)+tmp118_*tmp130_)-tmp419_*tmp131_+tmp421_*tmp129_)*mLocPolyn2_State_0_0)-mLocYIm)*mLocScNorm;

  mCompDer[1][0] = (((tmp122_)*(tmp414_)+(tmp116_)*tmp113_+(tmp417_)*tmp118_)-(tmp418_)*tmp419_+(tmp420_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][1] = (tmp422_+tmp128_*tmp118_+(tmp423_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][2] = (((tmp126_)*(tmp414_)+tmp127_*tmp118_)-(tmp424_)*tmp419_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][3] = tmp132_*(tmp107_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][4] = tmp426_;
  mCompDer[1][5] = tmp428_;
  mCompDer[1][6] = -(2*tmp131_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][7] = 0;
  mCompDer[1][8] = tmp129_*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][9] = (((tmp202_)*(tmp414_)+(tmp182_)*tmp113_+(tmp431_)*tmp118_)-(tmp432_)*tmp419_+(tmp433_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][10] = (((tmp289_)*(tmp414_)+(tmp263_)*tmp113_+(tmp436_)*tmp118_)-(tmp437_)*tmp419_+(tmp438_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][11] = (((tmp358_)*(tmp414_)+(tmp332_)*tmp113_+(tmp441_)*tmp118_)-(tmp442_)*tmp419_+(tmp443_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][12] = (((tmp376_)*(tmp414_)+(tmp369_)*tmp113_+(tmp446_)*tmp118_)-(tmp447_)*tmp419_+(tmp448_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][13] = (((tmp394_)*(tmp414_)+(tmp387_)*tmp113_+(tmp451_)*tmp118_)-(tmp452_)*tmp419_+(tmp453_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
  mCompDer[1][14] = (((tmp412_)*(tmp414_)+(tmp405_)*tmp113_+(tmp456_)*tmp118_)-(tmp457_)*tmp419_+(tmp458_)*tmp421_)*mLocPolyn2_State_0_0*mLocScNorm;
}


void cEqAppui_GL__TerFix_M2CPolyn2::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqAppui_GL__TerFix_M2CPolyn2 Has no Der Sec");
}

void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_0_0(double aVal){ mLocGL_0_0 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_0_1(double aVal){ mLocGL_0_1 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_0_2(double aVal){ mLocGL_0_2 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_1_0(double aVal){ mLocGL_1_0 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_1_1(double aVal){ mLocGL_1_1 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_1_2(double aVal){ mLocGL_1_2 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_2_0(double aVal){ mLocGL_2_0 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_2_1(double aVal){ mLocGL_2_1 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetGL_2_2(double aVal){ mLocGL_2_2 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetPolyn2_State_0_0(double aVal){ mLocPolyn2_State_0_0 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetPolyn2_State_1_0(double aVal){ mLocPolyn2_State_1_0 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetPolyn2_State_2_0(double aVal){ mLocPolyn2_State_2_0 = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetScNorm(double aVal){ mLocScNorm = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetXIm(double aVal){ mLocXIm = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetXTer(double aVal){ mLocXTer = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetYIm(double aVal){ mLocYIm = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetYTer(double aVal){ mLocYTer = aVal;}
void cEqAppui_GL__TerFix_M2CPolyn2::SetZTer(double aVal){ mLocZTer = aVal;}



double * cEqAppui_GL__TerFix_M2CPolyn2::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "GL_0_0") return & mLocGL_0_0;
   if (aName == "GL_0_1") return & mLocGL_0_1;
   if (aName == "GL_0_2") return & mLocGL_0_2;
   if (aName == "GL_1_0") return & mLocGL_1_0;
   if (aName == "GL_1_1") return & mLocGL_1_1;
   if (aName == "GL_1_2") return & mLocGL_1_2;
   if (aName == "GL_2_0") return & mLocGL_2_0;
   if (aName == "GL_2_1") return & mLocGL_2_1;
   if (aName == "GL_2_2") return & mLocGL_2_2;
   if (aName == "Polyn2_State_0_0") return & mLocPolyn2_State_0_0;
   if (aName == "Polyn2_State_1_0") return & mLocPolyn2_State_1_0;
   if (aName == "Polyn2_State_2_0") return & mLocPolyn2_State_2_0;
   if (aName == "ScNorm") return & mLocScNorm;
   if (aName == "XIm") return & mLocXIm;
   if (aName == "XTer") return & mLocXTer;
   if (aName == "YIm") return & mLocYIm;
   if (aName == "YTer") return & mLocYTer;
   if (aName == "ZTer") return & mLocZTer;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqAppui_GL__TerFix_M2CPolyn2::mTheAuto("cEqAppui_GL__TerFix_M2CPolyn2",cEqAppui_GL__TerFix_M2CPolyn2::Alloc);


cElCompiledFonc *  cEqAppui_GL__TerFix_M2CPolyn2::Alloc()
{  return new cEqAppui_GL__TerFix_M2CPolyn2();
}


