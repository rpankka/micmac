class cConvolSpec_U_INT2_Num0 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   23*(In[-3]+In[3])
				              +   883*(In[-2]+In[2])
				              +   7662*(In[-1]+In[1])
				              +   15632*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num0(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-3),-3,3,15,false){}
};

class cConvolSpec_U_INT2_Num1 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   5*(In[-4]+In[4])
				              +   162*(In[-3]+In[3])
				              +   1852*(In[-2]+In[2])
				              +   7933*(In[-1]+In[1])
				              +   12864*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num1(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-4),-4,4,15,false){}
};

class cConvolSpec_U_INT2_Num2 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   4*(In[-5]+In[5])
				              +   67*(In[-4]+In[4])
				              +   609*(In[-3]+In[3])
				              +   2945*(In[-2]+In[2])
				              +   7573*(In[-1]+In[1])
				              +   10372*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num2(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-5),-5,5,15,false){}
};

class cConvolSpec_U_INT2_Num3 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   6*(In[-6]+In[6])
				              +   53*(In[-5]+In[5])
				              +   326*(In[-4]+In[4])
				              +   1346*(In[-3]+In[3])
				              +   3702*(In[-2]+In[2])
				              +   6793*(In[-1]+In[1])
				              +   8316*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num3(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-6),-6,6,15,false){}
};

class cConvolSpec_U_INT2_Num4 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   2*(In[-8]+In[8])
				              +   12*(In[-7]+In[7])
				              +   64*(In[-6]+In[6])
				              +   263*(In[-5]+In[5])
				              +   842*(In[-4]+In[4])
				              +   2078*(In[-3]+In[3])
				              +   3964*(In[-2]+In[2])
				              +   5838*(In[-1]+In[1])
				              +   6642*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num4(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-8),-8,8,15,false){}
};

class cConvolSpec_U_INT2_Num5 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   1*(In[-10]+In[10])
				              +   7*(In[-9]+In[9])
				              +   28*(In[-8]+In[8])
				              +   95*(In[-7]+In[7])
				              +   276*(In[-6]+In[6])
				              +   682*(In[-5]+In[5])
				              +   1426*(In[-4]+In[4])
				              +   2531*(In[-3]+In[3])
				              +   3814*(In[-2]+In[2])
				              +   4877*(In[-1]+In[1])
				              +   5294*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num5(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-10),-10,10,15,false){}
};

class cConvolSpec_U_INT2_Num6 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   18*(In[-3]+In[3])
				              +   806*(In[-2]+In[2])
				              +   7599*(In[-1]+In[1])
				              +   15922*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num6(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-3),-3,3,15,false){}
};

class cConvolSpec_U_INT2_Num7 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   5*(In[-4]+In[4])
				              +   153*(In[-3]+In[3])
				              +   1813*(In[-2]+In[2])
				              +   7934*(In[-1]+In[1])
				              +   12958*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num7(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-4),-4,4,15,false){}
};

class cConvolSpec_U_INT2_Num8 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   3*(In[-5]+In[5])
				              +   62*(In[-4]+In[4])
				              +   588*(In[-3]+In[3])
				              +   2911*(In[-2]+In[2])
				              +   7594*(In[-1]+In[1])
				              +   10452*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num8(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-5),-5,5,15,false){}
};

class cConvolSpec_U_INT2_Num9 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   5*(In[-6]+In[6])
				              +   49*(In[-5]+In[5])
				              +   312*(In[-4]+In[4])
				              +   1319*(In[-3]+In[3])
				              +   3685*(In[-2]+In[2])
				              +   6824*(In[-1]+In[1])
				              +   8380*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num9(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-6),-6,6,15,false){}
};

class cConvolSpec_U_INT2_Num10 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   2*(In[-8]+In[8])
				              +   11*(In[-7]+In[7])
				              +   60*(In[-6]+In[6])
				              +   252*(In[-5]+In[5])
				              +   821*(In[-4]+In[4])
				              +   2057*(In[-3]+In[3])
				              +   3962*(In[-2]+In[2])
				              +   5872*(In[-1]+In[1])
				              +   6694*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num10(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-8),-8,8,15,false){}
};

class cConvolSpec_U_INT2_Num11 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   5*(In[-5]+In[5])
				              +   78*(In[-4]+In[4])
				              +   659*(In[-3]+In[3])
				              +   3022*(In[-2]+In[2])
				              +   7523*(In[-1]+In[1])
				              +   10194*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num11(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-5),-5,5,15,false){}
};

class cConvolSpec_U_INT2_Num12 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   2*(In[-12]+In[12])
				              +   8*(In[-11]+In[11])
				              +   23*(In[-10]+In[10])
				              +   63*(In[-9]+In[9])
				              +   152*(In[-8]+In[8])
				              +   331*(In[-7]+In[7])
				              +   650*(In[-6]+In[6])
				              +   1151*(In[-5]+In[5])
				              +   1836*(In[-4]+In[4])
				              +   2640*(In[-3]+In[3])
				              +   3423*(In[-2]+In[2])
				              +   3999*(In[-1]+In[1])
				              +   4212*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num12(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-12),-12,12,15,false){}
};

class cConvolSpec_U_INT2_Num13 : public cConvolSpec<U_INT2>
{
	public :
		bool IsCompiled() const { return true; }
		void Convol(U_INT2 * Out,U_INT2 * In,int aK0,int aK1)
		{
			In+=aK0;
			Out+=aK0;
			for (int aK=aK0; aK<aK1 ; aK++){
				*(Out++) =  (
				                  16384
				              +   2*(In[-5]+In[5])
				              +   43*(In[-4]+In[4])
				              +   483*(In[-3]+In[3])
				              +   2729*(In[-2]+In[2])
				              +   7694*(In[-1]+In[1])
				              +   10866*(In[0])
				            )>>15;
				In++;
			}
		}

		cConvolSpec_U_INT2_Num13(INT * aFilter):cConvolSpec<U_INT2>(aFilter-(-5),-5,5,15,false){}
};

