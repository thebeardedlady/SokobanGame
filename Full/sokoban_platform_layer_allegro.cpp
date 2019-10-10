#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>



#define FPS 60.0f
#define local_persist static
#define global_variable static
#define internal static

#define ArrayCount(array) (sizeof(array)/sizeof((array)[0]))
#define Max(a,b) a > b ? a : b
#define Min(a,b) a < b ? a : b

#define DEBUG 1
//#define _CRT_SECURE_NO_WARNINGS	


#if DEBUG
#define Assert(Expression) if(!(Expression)){*(int*)0 = 0;}
#else
#define Assert(Expression)
#endif




typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef s32 b32;
typedef s32 ixy;

typedef float r32;
typedef double r64;

#define TAU32 6.28318530718f
#define TAU64 6.28318530717958647692
#define CTAU32 8.0f
#define CTAU64 8.0
#define CTAUINT 8

inline r32
SqRt(r32 A)
{
	r32 Result = sqrtf(A);
	return Result;
}

inline s32
Sign(s32 A)
{
	s32 Result = A > 0 ? 1 : (A < 0 ? -1 : 0);
	return Result;
}

inline r32
Sign(r32 A)
{
	r32 Result = A > 0.0f ? 1.0f : (A < 0.0f ? -1.0f : 0.0f);
	return Result;
}

inline r32
Square(r32 A)
{
	r32 Result = A * A;
	return Result;
}

inline r64
Square(r64 A)
{
	r64 Result = A * A;
	return Result;
}

inline s32
Square(s32 A)
{
	s32 Result = A * A;
	return Result;
}
inline s64
Square(s64 A)
{
	s64 Result = A * A;
	return Result;
}

inline r32
Abs(r32 A)
{
	r32 Result = fabsf(A);
	return Result;
}

inline s32
Abs(s32 A)
{
	s32 Result = abs(A);
	return Result;
}

inline s64
Abs(s64 A)
{
	s64 Result = abs(A);
	return Result;
}

inline r32
Sine(r32 A)
{
	r32 Result = sinf(A);
	return Result;
}

inline r32
Cosine(r32 A)
{
	r32 Result = cosf(A);
	return Result;
}

inline r32
Tangent(r32 A)
{
	r32 Result = tanf(A);
	return Result;
}

inline r32
ArcTan2(r32 A, r32 B)
{
	r32 Result = atan2f(B, A);
	return Result;
}

inline r32
Cube(r32 A)
{
	r32 Result = A * A * A;
	return Result;
}

inline s32
Cube(s32 A)
{
	s32 Result = A * A * A;
	return Result;
}

inline r32
Floor(r32 A)
{
	r32 Result = floorf(A);
	return Result;
}

inline r32
Ceiling(r32 A)
{
	r32 Result = ceilf(A);
	return Result;

}

inline r32
Fractional(r32 A)
{
	r32 Result = A - Floor(A);
	return Result;
}


inline r32
FMod(r32 Num, r32 Mod)
{
	r32 Result = Fractional(Num / Mod) * Mod;
	return Result;
}



inline r32
Clamp(r32 Min, r32 A, r32 Max)
{
	r32 Result = A;
	if (A < Min)
	{
		Result = Min;
	}
	else if (A > Max)
	{
		Result = Max;
	}

	return Result;
}

inline s32
Clamp(s32 Min, s32 A, s32 Max)
{
	s32 Result = A;
	if (A < Min)
	{
		Result = Min;
	}
	else if (A > Max)
	{
		Result = Max;
	}

	return Result;
}

inline s64
Clamp(s64 Min, s64 A, s64 Max)
{
	s64 Result = A;
	if (A < Min)
	{
		Result = Min;
	}
	else if (A > Max)
	{
		Result = Max;
	}

	return Result;
}



/////////////////////////////////////////////////

union i2 {
	struct {
		s32 X;
		s32 Y;
	};
	s32 E[2];
};


inline i2
operator+(i2 A, i2 B)
{
	i2 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	return Result;
}

inline i2
operator-(i2 A, i2 B)
{
	i2 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	return Result;
}

inline i2
operator-(i2 A)
{
	i2 Result;
	Result.X = -A.X;
	Result.Y = -A.Y;
	return Result;
}

inline i2
operator*(s32 A, i2 B)
{
	i2 Result;
	Result.X = A * B.X;
	Result.Y = A * B.Y;
	return Result;
}

inline i2
operator*(i2 A, s32 B)
{
	i2 Result;
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	return Result;
}

inline i2
operator/(i2 A, s32 B)
{
	i2 Result;
	Result.X = A.X / B;
	Result.Y = A.Y / B;
	return Result;
}

inline b32
operator==(i2 A, i2 B)
{
	b32 Result = (A.X == B.X) && (A.Y == B.Y);
	return Result;
}

inline b32
operator!=(i2 A, i2 B)
{
	b32 Result = (A.X != B.X) || (A.Y != B.Y);
	return Result;
}

inline i2
operator+=(i2 A, i2 B)
{
	i2 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	return Result;
}

inline i2
operator-=(i2 A, i2 B)
{
	i2 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	return Result;
}


inline i2
I2(u32 Index, s32 Width)
{
	i2 Result;
	Result.X = ((s32)Index) % Width;
	Result.Y = ((s32)Index) / Width;
	return Result;
}

inline i2
I2(s32 X, s32 Y)
{
	i2 Result;
	Result.X = X;
	Result.Y = Y;
	return Result;
}

inline i2
I2(r32 X, r32 Y)
{
	i2 Result;
	Result.X = (s32)X;
	Result.Y = (s32)Y;
	return Result;
}

inline s32
Inner(i2 A, i2 B)
{
	s32 Result = (A.X * B.X) + (A.Y * B.Y);
	return Result;
}

inline s32
LengthSq(i2 A)
{
	s32 Result = Inner(A, A);
	return Result;
}

inline s32
TLength(i2 A)
{
	s32 Result = Abs(A.X) + Abs(A.Y);
	return Result;
}

inline s32
CLength(i2 A)
{
	s32 Result = Max(Abs(A.X), Abs(A.Y));
	return Result;
}

inline s32
DistanceSq(i2 A, i2 B)
{
	s32 Result = LengthSq(A - B);
	return Result;
}

inline s32
TDistance(i2 A, i2 B)
{
	s32 Result = TLength(A - B);
	return Result;
}

inline s32
CDistance(i2 A, i2 B)
{
	s32 Result = CLength(A - B);
	return Result;
}


inline s32
GetAngle(i2 A)
{
	s32 Result;

	if (A.X == 0) //Vertical Line
	{
		if (A.Y > 0)
		{
			Result = 2;
		}
		else if (A.Y < 0)
		{
			Result = 6;
		}
		else
		{
			Result = 
			printf("\nERROR: Trying to get the angle of the zero vector");
		}
	}
	else
	{
		s32 M = A.Y / A.X;
		if (M >= 0)
		{
			if (M <= 1)
			{
				Result = M;
			}
			else
			{
				Result = 2;
			}
			if (A.X > 0)
			{
			}
			else
			{
				Result += 4;
			}
		}
		else
		{
			if (M >= -1)
			{
				Result = M;
			}
			else
			{
				Result = -2;
			}
			if (A.X > 0)
			{
				Result += 8;
			}
			else
			{
				Result += 4;
			}
		}
	}
	return Result;
}

inline s32
KeepMetricAngleInRange(s32 Angle)
{
	s32 Result;
	if (Angle >= 0)
	{
		Result = Angle % CTAUINT;
	}
	else
	{
		Result = CTAUINT - ((-Angle) % CTAUINT);
	}

	return Result;
}

//NOTE(ian): Assumes the angle is between 0 and 8
inline s32
TSine(s32 Angle)
{
	s32 Result;
	if (Angle >= 0 && Angle < 2)
	{
		Result = Angle / 2;
	}
	else if (Angle >= 2 && Angle < 6)
	{
		Result = 2 - Angle / 2;
	}
	else
	{
		Result = -4 + Angle / 2;
	}
	return Result;
}

//NOTE(ian): Assumes the angle is between 0 and 8
inline s32
TCosine(s32 Angle)
{
	s32 Result;
	if (Angle >= 0 && Angle < 4)
	{
		Result = 1 - Angle / 2;
	}
	else
	{
		Result = -3 + Angle / 2;
	}
	return Result;
}

inline i2
TEuler(s32 Angle)
{
	i2 Result;
	Result.X = TCosine(Angle);
	Result.Y = TSine(Angle);
	return Result;
}



//NOTE(ian): Assumes the angle is between 0 and 8
inline s32
CSine(s32 Angle)
{
	r32 Result;
	if (Angle < 1)
	{
		Result = Angle;
	}
	else if (Angle < 3)
	{
		Result = 1;
	}
	else if (Angle < 5)
	{
		Result = 4 - Angle;
	}
	else if (Angle < 7)
	{
		Result = -1;
	}
	else
	{
		Result = Angle - 8;
	}

	return Result;
}


//NOTE(ian): Assumes the angle is between 0 and 8
inline s32
CCosine(s32 Angle)
{
	s32 Result;
	if (Angle < 1)
	{
		Result = 1;
	}
	else if (Angle < 3)
	{
		Result = 2 - Angle;
	}
	else if (Angle < 5)
	{
		Result = -1;
	}
	else if (Angle < 7)
	{
		Result = Angle - 6;
	}
	else
	{
		Result = 1;
	}

	return Result;
}

inline i2
CEuler(s32 Angle)
{
	i2 Result;
	Result.X = CCosine(Angle);
	Result.Y = CSine(Angle);
	return Result;
}



inline i2
ComplexMult(i2 A, i2 B)
{
	i2 Result;
	Result.X = A.X*B.X - A.Y * B.Y;
	Result.Y = A.X*B.Y + A.Y * B.X;
	return Result;
}

inline i2
Hadamard(i2 A, i2 B)
{
	i2 Result;
	Result.X = A.X * B.X;
	Result.Y = A.Y * B.Y;
	return Result;
}

inline i2
HadamardDiv(i2 A, i2 B)
{
	i2 Result;
	Result.X = A.X / B.X;
	Result.Y = A.Y / B.Y;
	return Result;
}

inline s32
Cross(i2 A, i2 B)
{
	s32 Result = A.X * B.Y - A.Y * B.X;
	return Result;
}

inline i2
Perp(i2 A)
{
	i2 Result = { -A.Y,A.X };
	return Result;
}

/////////////////////////////////////////////



union v2 {
	struct {
		r32 X;
		r32 Y;
	};
	r32 E[2];
};




inline v2
operator+(v2 A, v2 B)
{
	v2 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	return Result;
}

inline v2
operator-(v2 A, v2 B)
{
	v2 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	return Result;
}

inline v2
operator-(v2 A)
{
	v2 Result;
	Result.X = -A.X;
	Result.Y = -A.Y;
	return Result;
}

inline v2
operator*(r32 A, v2 B)
{
	v2 Result;
	Result.X = A * B.X;
	Result.Y = A * B.Y;
	return Result;
}

inline v2
operator*(v2 A, r32 B)
{
	v2 Result;
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	return Result;
}

inline v2
operator/(v2 A, r32 B)
{
	v2 Result;
	Result.X = A.X / B;
	Result.Y = A.Y / B;
	return Result;
}

inline b32
operator==(v2 A, v2 B)
{
	b32 Result = (A.X == B.X) && (A.Y == B.Y);
	return Result;
}

inline b32
operator!=(v2 A, v2 B)
{
	b32 Result = (A.X != B.X) || (A.Y != B.Y);
	return Result;
}

inline v2
operator+=(v2 A, v2 B)
{
	v2 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	return Result;
}

inline v2
operator-=(v2 A, v2 B)
{
	v2 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	return Result;
}

inline i2
I2(v2 A)
{
	i2 Result;
	Result.X = (s32)A.X;
	Result.Y = (s32)A.Y;
	return Result;
}

inline v2
V2(r32 X, r32 Y)
{
	v2 Result;
	Result.X = X;
	Result.Y = Y;
	return Result;
}

inline v2
V2(s32 X, s32 Y)
{
	v2 Result;
	Result.X = (r32)X;
	Result.Y = (r32)Y;
	return Result;
}

inline v2
V2(i2 A)
{
	v2 Result;
	Result.X = (r32)A.X;
	Result.Y = (r32)A.Y;
	return Result;
}

inline r32
Inner(v2 A, v2 B)
{
	r32 Result = (A.X * B.X) + (A.Y * B.Y);
	return Result;
}

inline r32
LengthSq(v2 A)
{
	r32 Result = Inner(A, A);
	return Result;
}

inline r32
Length(v2 A)
{
	r32 Result = SqRt(LengthSq(A));
	return Result;
}

inline r32
DistanceSq(v2 A, v2 B)
{
	r32 Result = LengthSq(A - B);
	return Result;
}

inline r32
Distance(v2 A, v2 B)
{
	r32 Result = Length(A - B);
	return Result;
}

inline v2
Normalized(v2 A)
{
	r32 Size = Length(A);
	Assert(Size != 0.0f);
	v2 Result = A / Size;
	return Result;
}


inline r32
GetAngle(v2 A)
{
	r32 Result = ArcTan2(A.X, A.Y);
	if (Result < 0.0f)
	{
		Result += TAU32;
	}
	return Result;
}

inline v2
Euler(r32 Angle)
{
	v2 Result;
	Result.X = Cosine(Angle);
	Result.Y = Sine(Angle);
	return Result;
}



/*
===================
==TAXICAB==METRIC==
===================
*/

inline r32
TLength(v2 A)
{
	r32 Result = Abs(A.X) + Abs(A.Y);
	return Result;
}

inline r32
TDistance(v2 A, v2 B)
{
	r32 Result = TLength(A - B);
	return Result;
}

/*
===================
=CHEBYSHEV==METRIC=
===================
*/

inline r32
CLength(v2 A)
{
	r32 Result = Max(Abs(A.X), Abs(A.Y));
	return Result;
}

inline r32
CDistance(v2 A, v2 B)
{
	r32 Result = CLength(A - B);
	return Result;
}

inline r32
CArcTan2(r32 X, r32 Y)
{
	r32 Result;

	if (X == 0.0f) //Vertical Line
	{
		if (Y > 0.0f)
		{
			Result = 2.0f;
		}
		else
		{
			Result = 6.0f;
		}
	}
	else
	{
		r32 M = Y / X;
		if (M >= 0.0f)
		{
			if (M <= 1.0f)
			{
				Result = M;
			}
			else
			{
				Result = 2.0f - (1.0f / M);
			}
			if (X > 0.0)
			{
			}
			else
			{
				Result += 4.0f;
			}
		}
		else
		{
			if (M >= -1.0f)
			{
				Result = M;
			}
			else
			{
				Result = -2.0f - (1.0f / M);
			}
			if (X > 0.0f)
			{
				Result += 8.0f;
			}
			else
			{
				Result += 4.0f;
			}
		}
	}

	return Result;
}


inline r32
CSine(r32 Angle)
{
	r32 Result;
	if (Angle < 1.0f)
	{
		Result = Angle;
	}
	else if (Angle < 3.0f)
	{
		Result = 1.0f;
	}
	else if (Angle < 5.0f)
	{
		Result = 4.0f - Angle;
	}
	else if (Angle < 7.0f)
	{
		Result = -1.0f;
	}
	else
	{
		Result = Angle - 8.0f;
	}

	return Result;
}

inline r32
CCosine(r32 Angle)
{
	r32 Result;
	if (Angle < 1.0f)
	{
		Result = 1.0f;
	}
	else if (Angle < 3.0f)
	{
		Result = 2.0f - Angle;
	}
	else if (Angle < 5.0f)
	{
		Result = -1.0f;
	}
	else if (Angle < 7.0f)
	{
		Result = Angle - 6.0f;
	}
	else
	{
		Result = 1.0f;
	}

	return Result;
}



inline v2
CRotate(v2 Center, v2 P, r32 Angle)
{
	r32 Theta = FMod(CArcTan2(P.X - Center.X, P.Y - Center.Y) + Angle, CTAU32);
	v2 Result = V2(CCosine(Theta), CSine(Theta)) * CLength(P - Center) + Center;
	return Result;
}

inline v2
CEuler(r32 Angle)
{
	v2 Result = v2{ CCosine(Angle),CSine(Angle) };
	return Result;
}



inline v2
ComplexMult(v2 A, v2 B)
{
	v2 Result;
	Result.X = A.X*B.X - A.Y * B.Y;
	Result.Y = A.X*B.Y + A.Y * B.X;
	return Result;
}

inline v2
ComplexDiv(v2 A, v2 B)
{
	v2 Result = ComplexMult(A, v2{ B.X,-B.Y }) / LengthSq(B);
	return Result;
}

inline b32
Opposite(v2 A, v2 B)
{
	b32 Result = ComplexDiv(B, A).X < 0.0f;
	return Result;
}

inline v2
Hadamard(v2 A, v2 B)
{
	v2 Result;
	Result.X = A.X * B.X;
	Result.Y = A.Y * B.Y;
	return Result;
}

inline v2
HadamardDiv(v2 A, v2 B)
{
	v2 Result;
	Result.X = A.X / B.X;
	Result.Y = A.Y / B.Y;
	return Result;
}

inline r32
Cross(v2 A, v2 B)
{
	r32 Result = A.X * B.Y - A.Y * B.X;
	return Result;
}

inline v2
Project(v2 A, v2 B)
{
	v2 Result = (Inner(A, B) / LengthSq(B)) * B;
	return Result;
}

inline v2
Perp(v2 A)
{
	v2 Result = { -A.Y,A.X };
	return Result;
}


inline v2
Perp(v2 A, v2 B)
{
	v2 Result = A - Project(A, B);
	return Result;
}

inline v2
Reflect(v2 Reflected, v2 Reflector)
{
	v2 Result = 2.0f * Project(Reflected, Reflector) - Reflected;
	return Result;
}


inline v2
Refract(v2 Incident, v2 LineRay, r32 ExitIndex, r32 EnterIndex)
{
	v2 Result;
	Result.X = (ExitIndex / EnterIndex) * Inner(Incident, LineRay);
	Result.Y = 1.0f - Square(Result.X);
	if (Result.Y >= 0.0f)
	{
		Result.Y = SqRt(Result.Y);
		Result = ComplexMult(LineRay, Result);
	}
	else
	{
		//NOTE(ian): Total internal reflection
		Result = v2{ 0.0f,0.0f };
	}
	return Result;
}

//NOTE(ian): 1) For Reflect() and Refract(), Incident and Normal are Normalized
//           2) Normal must be the proper line normal
//           3) These are taken from the paper cited on the Refraction Wikipedia article

/*
inline v2
Reflect(v2 Incident, v2 Normal)
{
v2 Result = Incident - 2.0f * Inner(Incident, Normal) * Normal;
return Result;
}

inline v2
Refract(v2 Incident, v2 Normal, r32 ExitIndex, r32 EnterIndex)
{
r32 RefractiveIndex = ExitIndex / EnterIndex;
r32 CosI = Inner(Incident, Normal);
r32 SinT2 = RefractiveIndex * RefractiveIndex * (1.0f - CosI * CosI);
if (SinT2 > 1.0f)
{
return v2{ 0.0f,0.0f };
}
v2 Result = RefractiveIndex * Incident - (RefractiveIndex + SqRt(1.0f - SinT2)) * Normal;
return Result;
}
*/

inline v2
Rotate(v2 Origin, v2 P, v2 Complex)
{
	v2 Result = ComplexMult(P - Origin, Complex) + Origin;
	return Result;
}




union i3 {
	struct {
		s32 X;
		s32 Y;
		s32 Z;
	};
	struct {
		i2 XY;
		s32 Z;
	};
	struct {
		s32 X;
		s32 YZ;
	};
	s32 E[3];
};


inline i3
operator+(i3 A, i3 B)
{
	i3 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	return Result;
}

inline i3
operator-(i3 A, i3 B)
{
	i3 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	return Result;
}

inline i3
operator-(i3 A)
{
	i3 Result;
	Result.X = -A.X;
	Result.Y = -A.Y;
	Result.Z = -A.Z;
	return Result;
}

inline i3
operator*(s32 A, i3 B)
{
	i3 Result;
	Result.X = A * B.X;
	Result.Y = A * B.Y;
	Result.Z = A * B.Z;
	return Result;
}

inline i3
operator*(i3 A, s32 B)
{
	i3 Result;
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	Result.Z = A.Z * B;
	return Result;
}

inline i3
operator/(i3 A, s32 B)
{
	i3 Result;
	Result.X = A.X / B;
	Result.Y = A.Y / B;
	Result.Z = A.Z / B;
	return Result;
}

inline b32
operator==(i3 A, i3 B)
{
	b32 Result = (A.X == B.X) && (A.Y == B.Y) && (A.Z == B.Z);
	return Result;
}

inline b32
operator!=(i3 A, i3 B)
{
	b32 Result = (A.X != B.X) || (A.Y != B.Y) || (A.Z != B.Z);
	return Result;
}


inline i3
I3(u32 Index, s32 Width, s32 Height)
{
	i3 Result;
	Result.Z = ((s32)Index) / (Width*Height);
	Result.X = ((s32)Index) % Width;
	Result.Y = (((s32)Index) / Width) - (Result.Z*Height);
	return Result;
}

inline i3
I3(s32 X, s32 Y, s32 Z)
{
	i3 Result;
	Result.X = X;
	Result.Y = Y;
	Result.Z = Z;
	return Result;
}

inline i3
I3(i2 XY, s32 Z)
{
	i3 Result;
	Result.X = XY.X;
	Result.Y = XY.Y;
	Result.Z = Z;
	return Result;
}

inline i3
I3(s32 X, i2 YZ)
{
	i3 Result;
	Result.X = X;
	Result.Y = YZ.X;
	Result.Z = YZ.Y;
	return Result;
}

inline i3
I3(r32 X, r32 Y, r32 Z)
{
	i3 Result;
	Result.X = (s32)X;
	Result.Y = (s32)Y;
	Result.Z = (s32)Z;
	return Result;
}

inline i3
I3(v2 XY, r32 Z)
{
	i3 Result;
	Result.X = (s32)XY.X;
	Result.Y = (s32)XY.Y;
	Result.Z = (s32)Z;
	return Result;
}

inline i3
I3(r32 X, v2 YZ)
{
	i3 Result;
	Result.X = (s32)X;
	Result.Y = (s32)YZ.X;
	Result.Z = (s32)YZ.Y;
	return Result;
}

inline s32
Inner(i3 A, i3 B)
{
	s32 Result = (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z);
	return Result;
}

inline s32
LengthSq(i3 A)
{
	s32 Result = Inner(A, A);
	return Result;
}

inline s32
TLength(i3 A)
{
	s32 Result = Abs(A.X) + Abs(A.Y) + Abs(A.Z);
	return Result;
}

inline s32
CLength(i3 A)
{
	s32 Result = Max(Abs(A.X), Abs(A.Y));
	Result = Max(Result, Abs(A.Z));
	return Result;
}

inline s32
DistanceSq(i3 A, i3 B)
{
	s32 Result = LengthSq(A - B);
	return Result;
}

inline s32
TDistance(i3 A, i3 B)
{
	s32 Result = TLength(A - B);
	return Result;
}

inline s32
CDistance(i3 A, i3 B)
{
	s32 Result = CLength(A - B);
	return Result;
}

inline i3
Hadamard(i3 A, i3 B)
{
	i3 Result;
	Result.X = A.X * B.X;
	Result.Y = A.Y * B.Y;
	Result.Y = A.Z * B.Z;
	return Result;
}

inline i3
HadamardDiv(i3 A, i3 B)
{
	i3 Result;
	Result.X = A.X / B.X;
	Result.Y = A.Y / B.Y;
	Result.Z = A.Z / B.Z;
	return Result;
}

inline i3
Cross(i3 A, i3 B)
{
	i3 Result;
	Result.X = A.Y*B.Z - A.Z*B.Y;
	Result.Y = A.Z*B.X - A.X*B.Z;
	Result.Z = A.X*B.Y - A.Y*B.X;
	return Result;

}


///////////////////////////////////////////////////////


union v3 {
	struct {
		r32 X;
		r32 Y;
		r32 Z;
	};
	struct {
		v2 XY;
		r32 Z;
	};
	struct {
		r32 X;
		v2 YZ;
	};
	struct {
		r32 R;
		r32 G;
		r32 B;
	};
	r32 E[3];
};

inline i3
I3(v3 A)
{
	i3 Result;
	Result.X = (s32)A.X;
	Result.Y = (s32)A.Y;
	Result.Z = (s32)A.Z;
	return Result;
}

inline v3
V3(i3 A)
{
	v3 Result;
	Result.X = (r32)A.X;
	Result.Y = (r32)A.Y;
	Result.Z = (r32)A.Z;
	return Result;
}

inline v3
V3(s32 X, s32 Y, s32 Z)
{
	v3 Result;
	Result.X = (r32)X;
	Result.Y = (r32)Y;
	Result.Z = (r32)Z;
	return Result;
}

inline v3
V3(i2 XY, s32 Z)
{
	v3 Result;
	Result.X = (r32)XY.X;
	Result.Y = (r32)XY.Y;
	Result.Z = (r32)Z;
	return Result;
}

inline v3
V3(s32 X, i2 YZ)
{
	v3 Result;
	Result.X = (r32)X;
	Result.Y = (r32)YZ.X;
	Result.Z = (r32)YZ.Y;
	return Result;
}

inline v3
V3(r32 X, r32 Y, r32 Z)
{
	v3 Result;
	Result.X = X;
	Result.Y = Y;
	Result.Z = Z;
	return Result;
}

inline v3
V3(v2 XY, r32 Z)
{
	v3 Result;
	Result.X = XY.X;
	Result.Y = XY.Y;
	Result.Z = Z;
	return Result;
}

inline v3
V3(r32 X, v2 YZ)
{
	v3 Result;
	Result.X = X;
	Result.Y = YZ.X;
	Result.Z = YZ.Y;
	return Result;
}

inline v3
operator+(v3 A, v3 B)
{
	v3 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	return Result;
}

inline v3
operator-(v3 A, v3 B)
{
	v3 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	return Result;
}

inline v3
operator-(v3 A)
{
	v3 Result;
	Result.X = -A.X;
	Result.Y = -A.Y;
	Result.Z = -A.Z;
	return Result;
}

inline v3
operator*(r32 A, v3 B)
{
	v3 Result;
	Result.X = A * B.X;
	Result.Y = A * B.Y;
	Result.Z = A * B.Z;
	return Result;
}

inline v3
operator*(v3 A, r32 B)
{
	v3 Result;
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	Result.Z = A.Z * B;
	return Result;
}

inline v3
operator/(v3 A, r32 B)
{
	v3 Result;
	r32 InvB = 1.0f / B;
	Result = InvB * A;
	return Result;
}


inline v3
operator+=(v3 A, v3 B)
{
	v3 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	return Result;
}

inline v3
operator-=(v3 A, v3 B)
{
	v3 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	return Result;
}

inline b32
operator==(v3 A, v3 B)
{
	b32 Result = (A.X == B.X) && (A.Y == B.Y) && (A.Z == B.Z);
	return Result;
}

inline b32
operator!=(v3 A, v3 B)
{
	b32 Result = (A.X != B.X) || (A.Y != B.Y) || (A.Z != B.Z);
	return Result;
}

inline r32
Inner(v3 A, v3 B)
{
	r32 Result = (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z);
	return Result;
}

inline r32
LengthSq(v3 A)
{
	r32 Result = Inner(A, A);
	return Result;
}

inline r32
Length(v3 A)
{
	r32 Result = SqRt(LengthSq(A));
	return Result;
}

inline r32
DistanceSq(v3 A, v3 B)
{
	r32 Result = LengthSq(A - B);
	return Result;
}

inline r32
Distance(v3 A, v3 B)
{
	r32 Result = Length(A - B);
	return Result;
}

inline r32
TLength(v3 A)
{
	r32 Result = Abs(A.X) + Abs(A.Y) + Abs(A.Z);
	return Result;
}

inline r32
CLength(v3 A)
{
	r32 Result = Max(Abs(A.X), Abs(A.Y));
	Result = Max(Result, Abs(A.Z));
	return Result;
}

inline r32
TDistance(v3 A, v3 B)
{
	r32 Result = TLength(A - B);
	return Result;
}

inline r32
CDistance(v3 A, v3 B)
{
	r32 Result = CLength(A - B);
	return Result;
}

inline v3
Normalized(v3 A)
{
	r32 Size = Length(A);
	Assert(Size != 0.0f);
	v3 Result = A / Size;
	return Result;
}

inline v3
Cross(v3 A, v3 B)
{
	v3 Result;
	Result.X = A.Y*B.Z - A.Z*B.Y;
	Result.Y = A.Z*B.X - A.X*B.Z;
	Result.Z = A.X*B.Y - A.Y*B.X;
	return Result;

}

inline v3
Hadamard(v3 A, v3 B)
{
	v3 Result;
	Result.X = A.X * B.X;
	Result.Y = A.Y * B.Y;
	Result.Z = A.Z * B.Z;
	return Result;
}





///////////////////////////////////////////////




union v4 {
	struct {
		r32 X;
		r32 Y;
		r32 Z;
		r32 W;
	};
	struct {
		r32 R;
		r32 G;
		r32 B;
		r32 A;
	};
	struct {
		v3 RGB;
		r32 A;
	};
};

inline v4
operator+(v4 A, v4 B)
{
	v4 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	Result.W = A.W + B.W;
	return Result;
}

inline v4
operator-(v4 A, v4 B)
{
	v4 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	Result.W = A.W - B.W;
	return Result;
}

inline v4
operator-(v4 A)
{
	v4 Result;
	Result.X = -A.X;
	Result.Y = -A.Y;
	Result.Z = -A.Z;
	Result.W = -A.W;
	return Result;
}

inline v4
operator*(r32 A, v4 B)
{
	v4 Result;
	Result.X = A * B.X;
	Result.Y = A * B.Y;
	Result.Z = A * B.Z;
	Result.W = A * B.W;
	return Result;
}

inline v4
operator*(v4 A, r32 B)
{
	v4 Result;
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	Result.Z = A.Z * B;
	Result.W = A.W * B;
	return Result;
}

inline v4
operator/(v4 A, r32 B)
{
	v4 Result;
	r32 InvB = 1.0f / B;
	Result = InvB * A;
	return Result;
}


inline v4
operator+=(v4 A, v4 B)
{
	v4 Result;
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	Result.W = A.W + B.W;
	return Result;
}

inline v4
operator-=(v4 A, v4 B)
{
	v4 Result;
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	Result.W = A.W - B.W;
	return Result;
}

inline r32
Inner(v4 A, v4 B)
{
	r32 Result = (A.X * B.X) + (A.Y * B.Y) + (A.Z * B.Z) + (A.W * B.W);
	return Result;
}

inline r32
LengthSq(v4 A)
{
	r32 Result = Inner(A, A);
	return Result;
}

inline r32
Length(v4 A)
{
	r32 Result = SqRt(LengthSq(A));
	return Result;
}

inline r32
DistanceSq(v4 A, v4 B)
{
	r32 Result = LengthSq(A - B);
	return Result;
}

inline r32
Distance(v4 A, v4 B)
{
	r32 Result = Length(A - B);
	return Result;
}

inline v4
Normalized(v4 A)
{
	r32 Size = Length(A);
	Assert(Size != 0.0f);
	v4 Result = A / Size;
	return Result;
}

inline v4
Hadamard(v4 A, v4 B)
{
	v4 Result;
	Result.X = A.X * B.X;
	Result.Y = A.Y * B.Y;
	Result.Z = A.Z * B.Z;
	Result.W = A.W * B.W;
	return Result;
}

inline v4
HadamardDiv(v4 A, v4 B)
{
	v4 Result;
	Result.X = A.X / B.X;
	Result.Y = A.Y / B.Y;
	Result.Z = A.Z / B.Z;
	Result.W = A.W / B.W;
	return Result;
}

inline u32
ConvertFromNormalizedVectorToColor(v4 A)
{
	u32 Result = ((u32)(A.A*255.0f) << 24) ||
		((u32)(A.R*255.0f) << 16) ||
		((u32)(A.G*255.0f) << 8) ||
		((u32)(A.B*255.0f) << 0);
	return Result;
}

inline v4
ConvertFromColorToNormalizedVector(u32 Color)
{
	v4 Result;
	Result.A = (r32)((Color >> 24) & 255) / 255.0f;
	Result.R = (r32)((Color >> 16) & 255) / 255.0f;
	Result.G = (r32)((Color >> 8) & 255) / 255.0f;
	Result.B = (r32)((Color >> 0) & 255) / 255.0f;
	return Result;
}


//////////////////////////////////////////////////////



union m2
{
	struct
	{
		r32 A;
		r32 B;
		r32 C;
		r32 D;
	};
	r32 E[4];
	struct
	{
		v2 AB;
		v2 CD;
	};
};


inline m2
operator+(m2 A, m2 B)
{
	m2 Result;
	Result.A = A.A + B.A;
	Result.B = A.B + B.B;
	Result.C = A.C + B.C;
	Result.D = A.D + B.D;
	return Result;
}

inline m2
operator-(m2 A, m2 B)
{
	m2 Result;
	Result.A = A.A - B.A;
	Result.B = A.B - B.B;
	Result.C = A.C - B.C;
	Result.D = A.D - B.D;
	return Result;
}

inline m2
operator-(m2 A)
{
	m2 Result;
	Result.A = -A.A;
	Result.B = -A.B;
	Result.C = -A.C;
	Result.D = -A.D;
	return Result;
}

inline m2
operator*(r32 C, m2 A)
{
	m2 Result;
	Result.A = C * A.A;
	Result.B = C * A.B;
	Result.C = C * A.C;
	Result.D = C * A.D;
	return Result;
}

inline m2
operator*(m2 A, r32 C)
{
	m2 Result;
	Result.A = C * A.A;
	Result.B = C * A.B;
	Result.C = C * A.C;
	Result.D = C * A.D;
	return Result;
}

inline m2
operator*(m2 A, m2 B)
{
	m2 Result;
	Result.A = A.A*B.A + A.B*B.C;
	Result.B = A.A*B.B + A.B*B.D;
	Result.C = A.C*B.A + A.D*B.C;
	Result.D = A.C*B.B + A.D*B.D;
	return Result;
}


inline r32
Trace(m2 A)
{
	r32 Result = A.A + A.D;
	return Result;
}

inline r32
Determinant(m2 A)
{
	r32 Result = A.A*A.D - A.B*A.C;
	return Result;
}

inline m2
Transpose(m2 A)
{
	m2 Result;
	Result.A = A.A;
	Result.B = A.C;
	Result.C = A.B;
	Result.D = A.D;
	return Result;
}

inline m2
Identity()
{
	m2 Result = m2{ 1.0f,0.0f,0.0f,1.0f };
	return Result;
}

inline m2
Invert(m2 A)
{
	r32 Det = Determinant(A);
	if (Det != 0.0f)
	{
		m2 Result;
		Result.A = A.D;
		Result.B = -A.B;
		Result.C = -A.C;
		Result.D = A.A;
		Result = (1.0f / Det) * Result;
		return Result;
	}
	else
	{
		return m2{ 0.0f,0.0f,0.0f,0.0f };
	}
}



/*
=================================
==============PRNG===============
=================================
*/


// NOTE(ian): this prng is based on Middle Square Weyl Sequnce PRNG
typedef struct {
	u64 Current;
	u64 W;
}prng_state;

inline void
Seed(prng_state *State, u64 Seed)
{
	State->Current = Seed;
	State->W = 0;

}

inline u64
NextRandom(prng_state *State)
{
	u64 S = 0xb5ad4eceda1ce2a9;
	State->Current *= State->Current;
	State->Current += (State->W += S);
	State->Current = (State->Current >> 32) | (State->Current << 32);
	return State->Current;
}



inline r32
RandomUnilateral(prng_state *State)
{
	r32 Result = (r32)NextRandom(State) / (r32)((u64)0xffffffffffffffff);
	return Result;
}

inline r32
RandomBilateral(prng_state* State)
{
	r32 Result = ((r32)NextRandom(State) / (r32)((u64)0xffffffffffffffff))*2.0f - 1.0f;
	return Result;
}

inline s32
RandomRange(prng_state *State, s32 Min, s32 Max)
{
	s32 Result = Min + (s32)(NextRandom(State) % (u64)((Max + 1) - Min));
	return Result;
}

inline r32
RandomRange(prng_state *State, r32 Min, r32 Max)
{
	r32 Result = Min + RandomUnilateral(State)*(Max - Min);
	return Result;
}

//////////////////////////////////////////////////////

typedef struct {
	v2 P;
	r32 R;
}circle;



/////////////////////////////////////////////////////////


//NOTE(ian): 2D Box

typedef struct {
	union {
		struct {
			i2 P;
			i2 Size;
		};
		struct {
			s32 X;
			s32 Y;
			s32 W;
			s32 H;
		};
	};
}b2;


inline b2
B2(i2 Pos, i2 Size)
{
	b2 Result = b2{ Pos,Size };
	return Result;
}

inline b2
B2(s32 X, s32 Y, s32 W, s32 H)
{
	b2 Result = b2{ X,Y,W,H };
	return Result;
}

inline b2
B2(v2 Pos, v2 Size)
{
	b2 Result = b2{ I2(Pos),I2(Size) };
	return Result;
}

inline b2
B2(r32 X, r32 Y, r32 W, r32 H)
{
	b2 Result = b2{ (s32)X,(s32)Y,(s32)W,(s32)H };
	return Result;
}



inline i2
Clamp(b2 Box, i2 Point)
{
	i2 Result;
	Result.X = Clamp(Box.P.X, Point.X, Box.P.X + Box.Size.X);
	Result.Y = Clamp(Box.P.Y, Point.Y, Box.P.Y + Box.Size.Y);
	return Result;
}



inline b32
InsideRect(b2 Box, i2 A)
{
	b32 Result = (A.X >= Box.P.X && A.X < Box.P.X + Box.Size.X) &&
		(A.Y >= Box.P.Y && A.Y < Box.P.Y + Box.Size.Y);
	return Result;
}

inline s32
GetArea(b2 Box)
{
	s32 Result = Box.Size.X * Box.Size.Y;
	return Result;
}

inline i2
BoxCenter(b2 Box)
{
	i2 Result = Box.P + (Box.Size / 2);
	return Result;
}

inline b2
CenterDim(i2 Center, i2 Size)
{
	b2 Result;
	Result.P = Center - (Size / 2);
	Result.Size = Size;

	return Result;
}

inline b2
TwoPoints(i2 P0, i2 P1)
{
	b2 Result;
	if (P0.X < P1.X)
	{
		Result.X = P0.X;
		Result.W = P1.X - P0.X;
	}
	else
	{
		Result.X = P1.X;
		Result.W = P0.X - P1.X;
	}
	if (P0.Y < P1.Y)
	{
		Result.Y = P0.Y;
		Result.H = P1.Y - P0.Y;
	}
	else
	{
		Result.Y = P1.Y;
		Result.H = P0.Y - P1.Y;
	}
	return Result;
}







inline b2
ExpandBox(b2 Box, i2 Point)
{
	b2 Result = Box;

	if (Point.X < Box.P.X)
	{
		Result.W += Box.X - Point.X;
		Result.X = Point.X;
	}
	else if (Point.X > Box.P.X + Box.Size.X)
	{
		Result.W = Point.X - Box.X;
	}
	if (Point.Y < Box.P.Y)
	{
		Result.H += Box.Y - Point.Y;
		Result.Y = Point.Y;
	}
	else if (Point.Y > Box.P.Y + Box.Size.Y)
	{
		Result.H = Point.Y - Box.Y;
	}

	return Result;
}

inline b2
MultiplePoints(i2* Points, u32 Num)
{
	b2 Result = TwoPoints(Points[0], Points[1]);

	for (u32 i = 2;
		i < Num;
		++i)
	{
		Result = ExpandBox(Result, Points[i]);
	}

	return Result;
}



inline b2
CombineRect(b2 BoxA, b2 BoxB)
{
	b2 Result = ExpandBox(BoxA, BoxB.P);
	Result = ExpandBox(Result, BoxB.P + BoxB.Size);
	return Result;

}



inline b32
Intersects(b2 A, b2 B)
{
	b32 Result = !(((A.P.X >= B.P.X + B.Size.X) ||
		(A.P.X + A.Size.X <= B.P.X)) ||
		((A.P.Y >= B.P.Y + B.Size.Y) ||
		(A.P.Y + A.Size.Y <= B.P.Y)));
	return Result;
}

inline b2
GetIntersection(b2 A, b2 B)
{
	b2 Result;

	Result.P.X = A.P.X > B.P.X ? A.P.X : B.P.X;
	Result.P.Y = A.P.Y > B.P.Y ? A.P.Y : B.P.Y;
	Result.Size.X = (A.Size.X + A.P.X < B.Size.X + B.P.X ?
		A.Size.X + (A.P.X - Result.P.X) : B.Size.X + (B.P.X - Result.P.X));
	Result.Size.Y = (A.Size.Y + A.P.Y < B.Size.Y + B.P.Y ?
		A.Size.Y + (A.P.Y - Result.P.Y) : B.Size.Y + (B.P.Y - Result.P.Y));

	return Result;
}

inline b2
ClipRect(b2 A, b2 B)
{
	if (Intersects(A, B))
	{
		return GetIntersection(A, B);
	}
	else
	{
		return b2{ 0,0,0,0 };
	}
}


inline void
GetCorners(b2 Box, i2 *Corners)
{
	Corners[0] = Box.P;
	Corners[1] = Box.P + i2{ Box.W,0 };
	Corners[2] = Box.P + i2{ 0,Box.H };
	Corners[3] = Box.P + Box.Size;
}


inline b32
InsideBox(b2 Box, i2 A)
{
	b32 Result = (A.X >= Box.P.X && A.X < Box.P.X + Box.Size.X) &&
		(A.Y >= Box.P.Y && A.Y < Box.P.Y + Box.Size.Y);
	return Result;
}

///////////////////////////////////////////



typedef struct {
	union {
		struct {
			v2 P;
			v2 Size;
		};
		struct {
			r32 X;
			r32 Y;
			r32 W;
			r32 H;
		};
	};
}r2;

inline b2
B2(r2 Rect)
{
	b2 Result;
	Result.X = (s32)Rect.X;
	Result.Y = (s32)Rect.Y;
	Result.W = (s32)Rect.W;
	Result.H = (s32)Rect.H;
	return Result;
}

inline r2
R2(b2 Rect)
{
	r2 Result;
	Result.X = (r32)Rect.X;
	Result.Y = (r32)Rect.Y;
	Result.W = (r32)Rect.W;
	Result.H = (r32)Rect.H;
	return Result;
}

inline r2
R2(v2 Pos, v2 Size)
{
	r2 Result = r2{ Pos,Size };
	return Result;
}

inline r2
R2(r32 X, r32 Y, r32 W, r32 H)
{
	r2 Result = r2{ X,Y,W,H };
	return Result;
}

inline r2
R2(i2 Pos, i2 Size)
{
	r2 Result = r2{ V2(Pos),V2(Size) };
	return Result;
}

inline r2
R2(s32 X, s32 Y, s32 W, s32 H)
{
	r2 Result = r2{ (r32)X,(r32)Y,(r32)W,(r32)H };
	return Result;
}

inline v2
Clamp(r2 Rect, v2 Point)
{
	v2 Result;
	Result.X = Clamp(Rect.P.X, Point.X, Rect.P.X + Rect.Size.X);
	Result.Y = Clamp(Rect.P.Y, Point.Y, Rect.P.Y + Rect.Size.Y);
	return Result;
}



inline b32
InsideRect(r2 Rect, v2 A)
{
	b32 Result = (A.X >= Rect.P.X && A.X < Rect.P.X + Rect.Size.X) &&
		(A.Y >= Rect.P.Y && A.Y < Rect.P.Y + Rect.Size.Y);
	return Result;
}

inline r32
GetArea(r2 Rect)
{
	r32 Result = Rect.Size.X * Rect.Size.Y;
	return Result;
}

inline v2
RectCenter(r2 Rect)
{
	v2 Result = Rect.P + 0.5f * Rect.Size;
	return Result;
}


inline r2
CircleExtent(circle Circle)
{
	r2 Result;
	Result.P = Circle.P - v2{ Circle.R,Circle.R };
	Result.Size.X = Circle.R * 2.0f;
	Result.Size.Y = Result.Size.X;
	return Result;
}

inline r2
CircleExtent(v2 CircleP, r32 Radius)
{
	r2 Result;
	Result.P = CircleP - v2{ Radius,Radius };
	Result.Size.X = Radius * 2.0f;
	Result.Size.Y = Result.Size.X;
	return Result;
}

inline r2
CenterDim(v2 Center, v2 Size)
{
	r2 Result;
	Result.P = Center - (Size * 0.5f);
	Result.Size = Size;

	return Result;
}

inline r2
TwoPoints(v2 P0, v2 P1)
{
	r2 Result;
	if (P0.X < P1.X)
	{
		Result.X = P0.X;
		Result.W = P1.X - P0.X;
	}
	else
	{
		Result.X = P1.X;
		Result.W = P0.X - P1.X;
	}
	if (P0.Y < P1.Y)
	{
		Result.Y = P0.Y;
		Result.H = P1.Y - P0.Y;
	}
	else
	{
		Result.Y = P1.Y;
		Result.H = P0.Y - P1.Y;
	}
	return Result;
}







inline r2
ExpandRect(r2 Rect, v2 Point)
{
	r2 Result = Rect;

	if (Point.X < Rect.P.X)
	{
		Result.W += Rect.X - Point.X;
		Result.X = Point.X;
	}
	else if (Point.X > Rect.P.X + Rect.Size.X)
	{
		Result.W = Point.X - Rect.X;
	}
	if (Point.Y < Rect.P.Y)
	{
		Result.H += Rect.Y - Point.Y;
		Result.Y = Point.Y;
	}
	else if (Point.Y > Rect.P.Y + Rect.Size.Y)
	{
		Result.H = Point.Y - Rect.Y;
	}

	return Result;
}


inline r32
VerticalFlip(r2 Rect, r32 Y)
{
	r32 Result = 2.0f * Y - Rect.Y - Rect.H;
	return Result;
}

inline r32
HorizontalFlip(r2 Rect, r32 X)
{
	r32 Result = 2.0f * X - Rect.X - Rect.W;
	return Result;
}


inline r2
MultiplePoints(v2* Points, u32 Num)
{
	r2 Result = TwoPoints(Points[0], Points[1]);

	for (u32 i = 2;
		i < Num;
		++i)
	{
		Result = ExpandRect(Result, Points[i]);
	}

	return Result;
}




inline r2
CombineRect(r2 RectA, r2 RectB)
{
	r2 Result = ExpandRect(RectA, RectB.P);
	Result = ExpandRect(Result, RectB.P + RectB.Size);
	return Result;

}



inline b32
Intersects(r2 A, r2 B)
{
	b32 Result = !(((A.P.X >= B.P.X + B.Size.X) ||
		(A.P.X + A.Size.X <= B.P.X)) ||
		((A.P.Y >= B.P.Y + B.Size.Y) ||
		(A.P.Y + A.Size.Y <= B.P.Y)));
	return Result;
}

inline r2
GetIntersection(r2 A, r2 B)
{
	r2 Result;

	Result.P.X = A.P.X > B.P.X ? A.P.X : B.P.X;
	Result.P.Y = A.P.Y > B.P.Y ? A.P.Y : B.P.Y;
	Result.Size.X = (A.Size.X + A.P.X < B.Size.X + B.P.X ?
		A.Size.X + (A.P.X - Result.P.X) : B.Size.X + (B.P.X - Result.P.X));
	Result.Size.Y = (A.Size.Y + A.P.Y < B.Size.Y + B.P.Y ?
		A.Size.Y + (A.P.Y - Result.P.Y) : B.Size.Y + (B.P.Y - Result.P.Y));

	return Result;
}

inline r2
ClipRect(r2 A, r2 B)
{
	if (Intersects(A, B))
	{
		return GetIntersection(A, B);
	}
	else
	{
		return r2{ 0.0f,0.0f,0.0f,0.0f };
	}
}


inline void
GetCorners(r2 Rect, v2 *Corners)
{
	Corners[0] = Rect.P;
	Corners[1] = Rect.P + v2{ Rect.W,0.0f };
	Corners[2] = Rect.P + v2{ 0.0f,Rect.H };
	Corners[3] = Rect.P + Rect.Size;
}

inline v2
Barycentric(r2 Rect, v2 Point)
{
	v2 Result;
	Result.X = (Point.X - Rect.X) / Rect.W;
	Result.Y = (Point.Y - Rect.Y) / Rect.H;
	return Result;
}

inline r2
RelativeBaryCentricRect(r2 Reference, r2 Referent)
{
	r2 Result;
	Result.P = Referent.P - Reference.P;
	Result.Size = HadamardDiv(Referent.Size, Reference.Size);
	Result.P = HadamardDiv(Result.P, Reference.Size);
	return Result;
}

inline r2
RelativeRectTransformation(r2 Reference, r2 Referent, r2 OtherRect)
{
	r2 RelativeRect = RelativeBaryCentricRect(Reference, Referent);
	OtherRect.P = OtherRect.P + Hadamard(RelativeRect.P, OtherRect.Size);
	OtherRect.Size = Hadamard(RelativeRect.Size, OtherRect.Size);
	return OtherRect;

}






/*
=================================
=============TWEENING============
=================================
*/


inline s32
Lerp(s32 A, s32 Numerator, s32 Denominator, s32 B)
{
	s32 Result = A + (Numerator * (B - A)) / Denominator;
	return Result;
}

inline i2
Lerp(i2 A, s32 Numerator, s32 Denominator, i2 B)
{
	i2 Result = A + (Numerator * (B - A)) / Denominator;
	return Result;
}

inline s32
Berp(s32 A, s32 B, s32 Numerator, s32 Denominator, s32 C, s32 D)
{
	s32 Result = A + (Cube(Numerator)*(D - 3 * C + 3 * B - A) + Square(Numerator)*Denominator*(3 * A - 6 * B + 3 * C)
		+ Numerator * Square(Denominator)*(3 * A + 3 * B)) / Cube(Denominator);
	return Result;
}

inline i2
Berp(i2 A, i2 B, s32 Numerator, s32 Denominator, i2 C, i2 D)
{
	i2 Result = A + (Cube(Numerator)*(D - 3 * C + 3 * B - A) + Square(Numerator)*Denominator*(3 * A - 6 * B + 3 * C)
		+ Numerator * Square(Denominator)*(3 * A + 3 * B)) / Cube(Denominator);
	return Result;
}

inline r32
Lerp(r32 A, r32 t, r32 B)
{
	r32 Result = (1.0f - t) * A + t * B;
	return Result;
}

inline v2
Lerp(v2 A, r32 t, v2 B)
{
	v2 Result = (1.0f - t) * A + t * B;
	return Result;
}

inline v3
Lerp(v3 A, r32 t, v3 B)
{
	v3 Result = (1.0f - t) * A + t * B;
	return Result;
}

inline v4
Lerp(v4 A, r32 t, v4 B)
{
	v4 Result = (1.0f - t) * A + t * B;
	return Result;
}

inline r2
Lerp(r2 A, r32 T, r2 B)
{
	r2 Result;
	Result.P = Lerp(A.P, T, B.P);
	Result.Size = Lerp(A.Size, T, B.Size);
	return Result;
}


inline r32
Berp(r32 A, r32 B, r32 t, r32 C, r32 D)
{
	r32 Result = Cube(1.0f - t) * A + 3.0f * Square(1.0f - t) * t * B +
		3.0f * (1.0f - t) * Square(t) * C + Cube(t) * D;
	return Result;
}

inline v2
Berp(v2 A, v2 B, r32 t, v2 C, v2 D)
{
	v2 Result = Cube(1.0f - t) * A + (3.0f * Square(1.0f - t) * t) * B +
		(3.0f * (1.0f - t) * Square(t)) * C + Cube(t) * D;
	return Result;
}


enum data_type {
	TYPE_NULL,
	TYPE_R32,
	TYPE_V2,
	TYPE_V3,
	TYPE_V4,
	TYPE_R2,
	/*
	TYPE_S32, //TODO(ian): should I support integer tweens?
	TYPE_B32,
	TYPE_I2,
	TYPE_I3,
	TYPE_B2
	*/
};

#define MAX_TWEENS 256

typedef struct {
	s32 Buffer[8];
	void* Data;
	r32 TotalTime;
	r32 TransTime;
	s32 Type;
} tween_object;


internal void
AddTweenR32(tween_object* Tweens, r32* Data, r32 Start, r32 Time, r32 End)
{
	for (s32 I = 0;
		I < MAX_TWEENS;
		++I)
	{
		if (Tweens[I].Type == TYPE_NULL)
		{
			r32* StartBuffer = (r32*)Tweens[I].Buffer;
			r32* EndBuffer = (r32*)(Tweens[I].Buffer + 1);
			Tweens[I].Data = (void*)Data;
			*StartBuffer = Start;
			*EndBuffer = End;
			Tweens[I].TotalTime = Time;
			Tweens[I].TransTime = 0.0f;
			Tweens[I].Type = TYPE_R32;
			break;
		}
	}
}

internal void
AddTweenV2(tween_object* Tweens, v2* Data, v2 Start, r32 Time, v2 End)
{
	for (s32 I = 0;
		I < MAX_TWEENS;
		++I)
	{
		if (Tweens[I].Type == TYPE_NULL)
		{
			v2* StartBuffer = (v2*)Tweens[I].Buffer;
			v2* EndBuffer = (v2*)(Tweens[I].Buffer + 2);
			Tweens[I].Data = (void*)Data;
			*StartBuffer = Start;
			*EndBuffer = End;
			Tweens[I].TotalTime = Time;
			Tweens[I].TransTime = 0.0f;
			Tweens[I].Type = TYPE_V2;
			break;
		}
	}
}

internal void
AddTweenV3(tween_object* Tweens, v3* Data, v3 Start, r32 Time, v3 End)
{
	for (s32 I = 0;
		I < MAX_TWEENS;
		++I)
	{
		if (Tweens[I].Type == TYPE_NULL)
		{
			v3* StartBuffer = (v3*)Tweens[I].Buffer;
			v3* EndBuffer = (v3*)(Tweens[I].Buffer + 3);
			Tweens[I].Data = (void*)Data;
			*StartBuffer = Start;
			*EndBuffer = End;
			Tweens[I].TotalTime = Time;
			Tweens[I].TransTime = 0.0f;
			Tweens[I].Type = TYPE_V3;
			break;
		}
	}
}

internal void
AddTweenV4(tween_object* Tweens, v4* Data, v4 Start, r32 Time, v4 End)
{
	for (s32 I = 0;
		I < MAX_TWEENS;
		++I)
	{
		if (Tweens[I].Type == TYPE_NULL)
		{
			v4* StartBuffer = (v4*)Tweens[I].Buffer;
			v4* EndBuffer = (v4*)(Tweens[I].Buffer + 4);
			Tweens[I].Data = (void*)Data;
			*StartBuffer = Start;
			*EndBuffer = End;
			Tweens[I].TotalTime = Time;
			Tweens[I].TransTime = 0.0f;
			Tweens[I].Type = TYPE_V4;
			break;
		}
	}
}

internal void
AddTweenR2(tween_object* Tweens, r2* Data, r2 Start, r32 Time, r2 End)
{
	for (s32 I = 0;
		I < MAX_TWEENS;
		++I)
	{
		if (Tweens[I].Type == TYPE_NULL)
		{
			r2* StartBuffer = (r2*)Tweens[I].Buffer;
			r2* EndBuffer = (r2*)(Tweens[I].Buffer + 4);
			Tweens[I].Data = (void*)Data;
			*StartBuffer = Start;
			*EndBuffer = End;
			Tweens[I].TotalTime = Time;
			Tweens[I].TransTime = 0.0f;
			Tweens[I].Type = TYPE_R2;
			break;
		}
	}
}

//NOTE(ian): if this is true then the tween is over
internal b32
TweenOjbect(tween_object* Tween, r32 dt)
{
	r32 T = 1.0f;
	b32 Result = true;
	Tween->TransTime += dt;
	if (Tween->TransTime < Tween->TotalTime)
	{
		T = Tween->TransTime / Tween->TotalTime;
		Result = false;
	}

	//T *= Square(T);

	if (Tween->Type == TYPE_NULL)
	{
		//NOTE(ian): Error! Trying to tween type null!!!!!
		Assert(0);
	}
	else if (Tween->Type == TYPE_R32)
	{
		r32 Start = *((r32*)Tween->Buffer);
		r32 End = *((r32*)(Tween->Buffer+1));
		r32 Value = Lerp(Start, T, End);
		r32* Data = (r32*)Tween->Data;
		*Data = Value;
	}
	else if (Tween->Type == TYPE_V2)
	{
		v2 Start = *((v2*)Tween->Buffer);
		v2 End = *((v2*)(Tween->Buffer + 2));
		v2 Value = Lerp(Start, T, End);
		v2* Data = (v2*)Tween->Data;
		*Data = Value;
	}
	else if (Tween->Type == TYPE_V3)
	{
		v3 Start = *((v3*)Tween->Buffer);
		v3 End = *((v3*)(Tween->Buffer + 3));
		v3 Value = Lerp(Start, T, End);
		v3* Data = (v3*)Tween->Data;
		*Data = Value;
	}
	else if (Tween->Type == TYPE_V4)
	{
		v4 Start = *((v4*)Tween->Buffer);
		v4 End = *((v4*)(Tween->Buffer + 4));
		v4 Value = Lerp(Start, T, End);
		v4* Data = (v4*)Tween->Data;
		*Data = Value;
	}
	else if (Tween->Type == TYPE_R2)
	{
		r2 Start = *((r2*)Tween->Buffer);
		r2 End = *((r2*)(Tween->Buffer + 4));
		r2 Value = Lerp(Start, T, End);
		r2* Data = (r2*)Tween->Data;
		*Data = Value;
	}

	return Result;
}


internal void
TweenAllObjects(tween_object* Tweens, r32 dt)
{
	for (s32 I = 0;
		I < MAX_TWEENS;
		++I)
	{
		if (Tweens[I].Type != TYPE_NULL)
		{
			if (TweenOjbect(&Tweens[I], dt))
			{
				Tweens[I].Type = TYPE_NULL;
			}
		}
	}
}


/*
=================================
==========BIT=OPERATIONS=========
=================================
*/

inline b32
AreBitsSet(s32 Field, s32 Mask)
{
	b32 Result = ((Field & Mask) == Mask);
	return Result;
}

inline b32
AreAnyBitsSet(s32 Field, s32 Mask)
{
	b32 Result = ((Field & Mask) != 0);
	return Result;
}

inline s32
SetBits(s32 Field, s32 Mask)
{
	s32 Result = Field | Mask;
	return Result;
}

inline s32
EraseBits(s32 Field, s32 Mask)
{
	s32 Result = (Field & ~Mask);
	return Result;
}

/////////////////////////////////////////////

inline u32
GetQuadrant(v2 A)
{
	/*
	Conventional Quadrant Space

	1 - I. Quadrant
	2 - II. Quadrant
	3 - III. Quadrant
	4 - IV. Quadrant
	*/


	u32 Result = 0;
	if (A.X >= 0.0f)
	{
		if (A.Y >= 0.0f)
		{
			Result = 1;
		}
		else
		{
			Result = 4;
		}
	}
	else
	{
		if (A.Y >= 0.0f)
		{
			Result = 2;
		}
		else
		{
			Result = 3;
		}
	}

	return Result;
}

inline s32
GetSlantedQuad(v2 A)
{
	/*
	0 - Positive X
	1 - Positive Y
	2 - Negative X
	3 - Negative Y
	*/


	s32 Result;
	if (Abs(A.X) >= Abs(A.Y))
	{
		if (A.X >= 0)
		{
			Result = 0;
		}
		else
		{
			Result = 2;
		}
	}
	else
	{
		if (A.Y >= 0)
		{
			Result = 1;
		}
		else
		{
			Result = 3;
		}
	}

	return Result;
}






internal s32
OutCode(r2 *Rect, v2 A)
{
	/*
	const int INSIDE = 0; // 0000
	const int LEFT = 1;   // 0001
	const int RIGHT = 2;  // 0010
	const int BOTTOM = 4; // 0100
	const int TOP = 8;    // 1000
	*/


	s32 Code = 0;

	if (A.X < Rect->P.X)
	{
		Code |= 1;
	}
	else if (A.X > Rect->P.X + Rect->Size.X)
	{
		Code |= 2;
	}
	if (A.Y < Rect->P.Y)
	{
		Code |= 4;
	}
	else if (A.Y > Rect->P.Y + Rect->Size.Y)
	{
		Code |= 8;
	}

	return Code;
}

internal void
ClipLine(r2 *Rect, v2 *A, v2 *B)
{
	s32 Outcode0 = OutCode(Rect, *A);
	s32 Outcode1 = OutCode(Rect, *B);
	b32 accept = false;

	while (true) {
		if (!(Outcode0 | Outcode1))
		{
			accept = true;
			break;
		}
		else if (Outcode0 & Outcode1)
		{
			A->X = 0.0f;
			A->Y = 0.0f;
			B->X = 0.0f;
			B->Y = 0.0f;
			break;
		}
		else
		{
			v2 C;
			s32 OutcodeOut = Outcode0 ? Outcode0 : Outcode1;

			if (OutcodeOut & 8)
			{
				C.X = A->X + (B->X - A->X) * ((Rect->P.Y + Rect->Size.Y) - A->Y) / (B->Y - A->Y);
				C.Y = (Rect->P.Y + Rect->Size.Y);
			}
			else if (OutcodeOut & 4)
			{
				C.X = A->X + (B->X - A->X) * (Rect->P.Y - A->Y) / (B->Y - A->Y);
				C.Y = Rect->P.Y;
			}
			else if (OutcodeOut & 2)
			{
				C.Y = A->Y + (B->Y - A->Y) * ((Rect->P.X + Rect->Size.X) - A->X) / (B->X - A->X);
				C.X = (Rect->P.X + Rect->Size.X);
			}
			else if (OutcodeOut & 1)
			{
				C.Y = A->Y + (B->Y - A->Y) * (Rect->P.X - A->X) / (B->X - A->X);
				C.X = Rect->X;
			}

			if (OutcodeOut == Outcode0) {
				*A = C;
				Outcode0 = OutCode(Rect, *A);
			}
			else {
				*B = C;
				Outcode1 = OutCode(Rect, *B);
			}
		}
	}
}

/*
=================================
========MEMORY=MANAGEMENT========
=================================
*/

inline void*
AllocateChunk(u32 Bytes)
{
	void* Result = (void*)malloc(Bytes);
	return Result;
}

inline void
FreeChunk(void* Chunk)
{
	free(Chunk);
}



/*
=================================
============RENDERING============
=================================
*/


#define GRID_PIXEL_LENGTH 32.0F


typedef struct {
	ALLEGRO_BITMAP* Bitmap;
	ALLEGRO_COLOR Tint;
	r2 Region;
	r2 Rect;
	v2 Center;
	v2 Offset;
	r32 Angle;
	s32 Flags;
}texture;

typedef texture texture_group[50];

#define NUM_TEXTURES 1



#define NUM_OBJECT_TYPES 13

enum object_id {
	ATLAS_ID,
	METRICLESS_BLOCK_ID,
	METRICLESS_WALL_ID,
	CHEBYSHEV_WALL_ID,
	CHEBYSHEV_BLOCK_ID,
	BLANK_ID,
	PLAYER_ID,
	GRID_A_ID,
	GRID_B_ID,
	RECT_UP_LEFT_ID,
	RECT_UP_RIGHT_ID,
	RECT_DOWN_LEFT_ID,
	RECT_DOWN_RIGHT_ID

};

void
DrawRect(texture Texture)
{
	ALLEGRO_COLOR PreMulColor = al_premul_rgba_f(Texture.Tint.r, Texture.Tint.g, Texture.Tint.b, Texture.Tint.a);

	al_draw_tinted_scaled_rotated_bitmap_region(Texture.Bitmap, Texture.Region.X, Texture.Region.Y, Texture.Region.W, Texture.Region.H,
		PreMulColor, Texture.Center.X, Texture.Center.Y, (Texture.Rect.X+Texture.Offset.X)*GRID_PIXEL_LENGTH, (Texture.Rect.Y+Texture.Offset.Y)*GRID_PIXEL_LENGTH, 
		Texture.Rect.W *GRID_PIXEL_LENGTH/ Texture.Region.W, Texture.Rect.H *GRID_PIXEL_LENGTH/ Texture.Region.H, Texture.Angle, Texture.Flags);
}


//NOTE(ian):
//data for quad is laid out: 0) top left; 1) bottom left; 2) top right ; 3) bottom right


void
DrawQuad(v2* Vertices, v4 Color, texture Texture)
{
	ALLEGRO_VERTEX Quad[6];


	v2 TransformedVertices[4];

	for (s32 I = 0;
		I < 4;
		++I)
	{
		TransformedVertices[I] = Vertices[I] * 32.0f;
	}


	Quad[0].x = TransformedVertices[0].X;
	Quad[0].y = TransformedVertices[0].Y;
	Quad[0].z = 0.0f;
	Quad[0].u = Texture.Region.X+0.5f;
	Quad[0].v = Texture.Region.Y+0.5f;
	Quad[0].color = al_map_rgba_f(Color.R,Color.G,Color.B,Color.A);

	Quad[1].x = TransformedVertices[1].X;
	Quad[1].y = TransformedVertices[1].Y;
	Quad[1].z = 0.0f;
	Quad[1].u = Texture.Region.X+0.5f;
	Quad[1].v = Texture.Region.Y+Texture.Region.H+0.5f;
	Quad[1].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);


	Quad[2].x = TransformedVertices[3].X;
	Quad[2].y = TransformedVertices[3].Y;
	Quad[2].z = 0.0f;
	Quad[2].u = Texture.Region.X + Texture.Region.W+0.5f;
	Quad[2].v = Texture.Region.Y + Texture.Region.H + 0.5f;
	Quad[2].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);


	Quad[3].x = TransformedVertices[0].X;
	Quad[3].y = TransformedVertices[0].Y;
	Quad[3].z = 0.0f;
	Quad[3].u = Texture.Region.X + 0.5f;
	Quad[3].v = Texture.Region.Y + 0.5f;
	Quad[3].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);

	Quad[4].x = TransformedVertices[2].X;
	Quad[4].y = TransformedVertices[2].Y;
	Quad[4].z = 0.0f;
	Quad[4].u = Texture.Region.X + Texture.Region.W+0.5f;
	Quad[4].v = Texture.Region.Y + 0.5f;
	Quad[4].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);


	Quad[5].x = TransformedVertices[3].X;
	Quad[5].y = TransformedVertices[3].Y;
	Quad[5].z = 0.0f;
	Quad[5].u = Texture.Region.X + Texture.Region.W + 0.5f;
	Quad[5].v = Texture.Region.Y + Texture.Region.H + 0.5f;
	Quad[5].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);

	s32 NumDrawn = al_draw_prim(Quad, NULL, Texture.Bitmap, 0, 6, ALLEGRO_PRIM_TRIANGLE_FAN);

	Assert(NumDrawn > 0);

}

internal void
DrawSpecialQuad(texture* TextureGroup, r2 Screen, v2 LightP, r32 GameplayZ, r32 LightZ, r32 WallZ, s32 TextureIndex)
{
	v2 Vertices[4];
	r2 Rect = TextureGroup[TextureIndex].Rect;

	v2 GameplayPos = Rect.P;
	r32 T = (WallZ - LightZ - (DistanceSq(GameplayPos, LightP) / GetArea(Screen))) / (GameplayZ - LightZ);
	Vertices[0] = (GameplayPos - LightP) * T + LightP;

	GameplayPos = Rect.P + V2(0.0f, Rect.H);
	T = (WallZ - LightZ - (DistanceSq(GameplayPos, LightP) / GetArea(Screen))) / (GameplayZ - LightZ);
	Vertices[1] = (GameplayPos - LightP) * T + LightP;

	GameplayPos = Rect.P + V2(Rect.W, 0.0f);
	T = (WallZ - LightZ - (DistanceSq(GameplayPos, LightP) / GetArea(Screen))) / (GameplayZ - LightZ);
	Vertices[2] = (GameplayPos - LightP) * T + LightP;

	GameplayPos = Rect.P + Rect.Size;
	T = (WallZ - LightZ - (DistanceSq(GameplayPos, LightP) / GetArea(Screen))) / (GameplayZ - LightZ);
	Vertices[3] = (GameplayPos - LightP) * T + LightP;


	if (Vertices[0].X < Vertices[3].X && Vertices[0].Y < Vertices[3].Y
		&& Vertices[1].X < Vertices[2].X && Vertices[1].Y > Vertices[2].Y)
	{
		DrawQuad(Vertices, v4{ 1.0f,1.0f,1.0f,1.0f }, TextureGroup[TextureIndex]);
	}
}


internal void
CreateCuboidFace(ALLEGRO_VERTEX *Face, v3 CuboidPos, v3 CuboidDim, s32 DiscardedFaceE, b32 FaceDimBool, v4 Color, texture Texture)
{
	s32 FaceE[2];
	v3 CuboidFaceDim = CuboidDim;
	if (DiscardedFaceE == 0)
	{
		FaceE[0] = 1;
		FaceE[1] = 2;
		CuboidFaceDim.E[0] = 0.0f;
	}
	else if (DiscardedFaceE == 1)
	{
		FaceE[0] = 0;
		FaceE[1] = 2;
		CuboidFaceDim.E[1] = 0.0f;
	}
	else
	{
		FaceE[0] = 0;
		FaceE[1] = 1;
		CuboidFaceDim.E[2] = 0.0f;
	}

	v3 CuboidFacePos = CuboidPos;

	if (FaceDimBool)
	{
		CuboidFacePos.E[DiscardedFaceE] += CuboidDim.E[DiscardedFaceE];
	}

	v3 FacePoints[4];


	for (s32 I = 0;
		I < 2;
		++I)
	{
		for (s32 J = 0;
			J < 2;
			++J)
		{
			FacePoints[I * 2 + J] = CuboidFacePos;
			if (I > 0)
			{
				FacePoints[I * 2 + J].E[FaceE[0]] += CuboidFaceDim.E[FaceE[0]];
			}
			if (J > 0)
			{
				FacePoints[I * 2 + J].E[FaceE[1]] += CuboidFaceDim.E[FaceE[1]];
			}
		}
	}


	s32 VertexMap[] = { 0,3,1,1,4,4,2,5 };


	for (s32 I = 0;
		I < 2;
		++I)
	{
		for (s32 J = 0;
			J < 2;
			++J)
		{
			for (s32 K = 0;
				K < 2;
				++K)
			{
				Face[VertexMap[I * 4 + J * 2 + K]].x = FacePoints[I * 2 + J].X;
				Face[VertexMap[I * 4 + J * 2 + K]].y = FacePoints[I * 2 + J].Y;
				Face[VertexMap[I * 4 + J * 2 + K]].z = FacePoints[I * 2 + J].Z;

			}
		}
	}

	Face[0].u = Texture.Region.X + 0.5f;
	Face[0].v = Texture.Region.Y + 0.5f;
	Face[0].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);

	Face[1].u = Texture.Region.X + 0.5f;
	Face[1].v = Texture.Region.Y + Texture.Region.H + 0.5f;
	Face[1].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);


	Face[2].u = Texture.Region.X + Texture.Region.W + 0.5f;
	Face[2].v = Texture.Region.Y + Texture.Region.H + 0.5f;
	Face[2].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);


	Face[3].u = Texture.Region.X + 0.5f;
	Face[3].v = Texture.Region.Y + 0.5f;
	Face[3].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);

	Face[4].u = Texture.Region.X + Texture.Region.W + 0.5f;
	Face[4].v = Texture.Region.Y + 0.5f;
	Face[4].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);


	Face[5].u = Texture.Region.X + Texture.Region.W + 0.5f;
	Face[5].v = Texture.Region.Y + Texture.Region.H + 0.5f;
	Face[5].color = al_map_rgba_f(Color.R, Color.G, Color.B, Color.A);


}

internal void
DrawCuboid(v3 CuboidPos, v3 CuboidDim, texture Texture)
{
	ALLEGRO_VERTEX Vertices[36];

	for (s32 I = 0;
		I < 3;
		++I)
	{
		for (s32 J = 0;
			J < 1;
			++J)
		{
			CreateCuboidFace(&Vertices[(6 * (I * 2 + J))], CuboidPos, CuboidDim, I, J, v4{ 1.0f,1.0f,1.0f,1.0f }, Texture);
		}
	}





	al_draw_prim(Vertices, NULL, Texture.Bitmap, 0, 18, ALLEGRO_PRIM_TRIANGLE_FAN);
	al_draw_prim(Vertices, NULL, Texture.Bitmap, 18, 36, ALLEGRO_PRIM_TRIANGLE_FAN);
	//al_draw_prim(Vertices, NULL, Texture.Bitmap, 12, 18, ALLEGRO_PRIM_TRIANGLE_LIST);
	//al_draw_prim(Vertices, NULL, Texture.Bitmap, 18, 24, ALLEGRO_PRIM_TRIANGLE_LIST);
	//al_draw_prim(Vertices, NULL, Texture.Bitmap, 24, 30, ALLEGRO_PRIM_TRIANGLE_LIST);
	//al_draw_prim(Vertices, NULL, Texture.Bitmap, 30, 36, ALLEGRO_PRIM_TRIANGLE_LIST);

	/*
	for (s32 I = 0;
	I < 12;
	++I)
	{
	for (s32 J = 0;
	J < 3;
	++J)
	{
	al_draw_line(Vertices[I * 3 + J].x, Vertices[I * 3 + J].y, Vertices[I * 3 + ((J + 1) % 3)].x, Vertices[I * 3 + ((J + 1) % 3)].y, al_map_rgb_f(1, 1, 1), 2);
	}
	}
	*/

}


/*
=================================
=============iNPUT===============
=================================
*/



typedef struct {
	r32 Time;
	u32 KeyOne;
	u32 KeyTwo;
	s32 NumPresses;
	b32 JustPressed;
	b32 JustReleased;
	b32 Pressed;
}key_action;

#define NUM_KEY_ACTIONS 28

enum ACTION_TYPES {
	RIGHT,
	RESTART,
	UP,
	UNDO,
	LEFT,
	SELECT,
	DOWN,
	BACK,
	EDITOR_RUN,
	EDITOR_LEFT_CLICK,
	EDITOR_RIGHT_CLICK,
	EDITOR_TOOL_SELECT,
	EDITOR_TOOL_BRUSH,
	EDITOR_TOOL_ERASE,
	EDITOR_TOOL_RECTANGLE,
	EDITOR_TOOL_EYEDROPPER,
	EDITOR_TOOL_LINK,
	EDITOR_ACT_TOGGLE_GRID,
	EDITOR_ACT_TOGGLE_LINKS,
	EDITOR_ACT_UNDO,
	EDITOR_ACT_REDO,
	EDITOR_ACT_CUT,
	EDITOR_ACT_COPY,
	EDITOR_ACT_PASTE,
	EDITOR_SCROLL_LEFT,
	EDITOR_SCROLL_RIGHT,
	EDITOR_SCROLL_UP,
	EDITOR_SCROLL_DOWN
};



typedef struct {
	i2 Move;
	s32 Num;
}input_scan_data;

typedef struct {
	key_action Actions[NUM_KEY_ACTIONS];
	i2 MousePos;
	i2 ChangeInMousePos;
	s32 MouseWheel;
	i2 PrimaryInputtedMove;
	i2 SecondaryInputtedMove;
	b32 HasInputtedMove;
	b32 ReceivedInput;
	r32 TimeSinceInputChange;
	r32 dt;
}user_input;

/*
=================================
============LEVEL=DATA===========
=================================
*/

enum event_type {
	NO_EVENT,
	MOVED_LATERALLY,
	MOVED_DIAGONALLY,
	CRATE_CHANGED_STATE,
	SINGLE_STEP_FALL,
	INVISIBLE_HAPPENED,
	UNDO_HAPPENED
};


#define PHYSICS_FLAGS_MASK 0x1f
#define TYPE_FLAGS_MASK 0xe0

//TODO(ian): should there be a separate type varaible?

enum entity_flags {
	EMPTY_FLAG = 0,
	CONNECTED_TO_CHEBYSHEV = 1, //first 6 are physics flags
	SURROUNDED_BY_METRICLESS = 2,
	SOMETHING_UNDERNEATH = 4,
	CHANGING_TO_CHEBYSHEV = 8,
	CHANGING_TO_METRICLESS = 16,
	PLAYER_FLAG = 32, //next 3 flags are types
	CHEBYSHEV_FLAG = 64,
	METRICLESS_FLAG = 128,
	INVISIBLE_FLAG = 256, //next 3 flags are attributes
	CHANGING_TO_INVISIBLE = 512,
	DIAGONAL_ACTIVATED = 1024
};


typedef struct {
	r2 Rect;
	i2 Pos;
	i2 Move;
	s32 GroupID;
	s32 ID;//TODO(ian): Is this needed?
	s32 Flags;
} block;

#define MAX_LEVEL_WIDTH 512
#define MAX_LEVEL_HEIGHT 512
#define MAX_BLOCKS_PER_LEVEL 128
#define MAX_PUZZLES_PER_LEVEL 32

//NOTE(ian): ~300k per level
typedef struct {
	s8 Immutables[MAX_LEVEL_WIDTH*MAX_LEVEL_HEIGHT];
	block Mutables[MAX_BLOCKS_PER_LEVEL];
	b2 Puzzles[MAX_PUZZLES_PER_LEVEL];
	i2 LevelSize;
	s32 NumPuzzles;
	s32 NumMutables;
	s32 ID;
}level;

/*
=================================
=======STB=TILEMAP=EDITOR========
=================================
*/

//#define EDITOR_RUNNING
#ifdef EDITOR_RUNNING

#include "stb-master\stb_tilemap_editor.h"


texture_group EditorTextures;

#define GAME_ELEMENTS_LAYER_MASK 127
#define PUZZLE_DATA_LAYER_MASK 128
#define LEVEL_DATA_LAYER_MASK 256



void 
EditorDrawRect(int x0, int y0, int x1, int y1, unsigned int color)
{
	al_draw_filled_rectangle((r32)x0, (r32)y0, (r32)x1, (r32)y1, al_map_rgb((char)((color >> 16) & 255), (char)((color >> 8) & 255), (char)((color >> 0) & 255)));
}

void
EditorDrawTile(int x0, int y0, unsigned short id, int highlight, float *data)
{
	//TODO(ian): unify block/object naming conventions
	//TODO(ian): once the editor is working, change this logic
	s32 TextureIndex = EMPTY_TEXTURE;

	if (id > 0 && id < 1000)
	{
		TextureIndex = id;
	}


	al_draw_tinted_scaled_rotated_bitmap_region(EditorTextures[TextureIndex].Bitmap, EditorTextures[TextureIndex].Region.X, EditorTextures[TextureIndex].Region.Y,
		EditorTextures[TextureIndex].Region.W, EditorTextures[TextureIndex].Region.H,al_map_rgb(255,255,255), 0.0f, 0.0f, (r32)x0, (r32)y0, 1.0f, 1.0f, 0.0f, 0);
}


unsigned int 
EditorPropType(int n, short* tiles, float* params)
{
	/*
	STBTE_PROP_int       /* uses a slider to adjust value     */
	//      //     STBTE_PROP_float     /* uses a weird multi-axis control   */
	//      //     STBTE_PROP_bool      /* uses a checkbox to change value   */
	if (tiles[8] == LEVEL_DATA_STARTING_ID) //level data
	{
		if (n < 2)
		{
			int DataTypes[2] = {
				STBTE_PROP_int,
				STBTE_PROP_int
			};
			return DataTypes[n];
		} 
	}
	return STBTE_PROP_none;
}

const char* 
EditorPropName(int n, short* tiledata, float* params)
{
	/*
	STBTE_PROP_int       /* uses a slider to adjust value     */
	//      //     STBTE_PROP_float     /* uses a weird multi-axis control   */
	//      //     STBTE_PROP_bool      /* uses a checkbox to change value   */
	if (tiledata[8] == LEVEL_DATA_STARTING_ID) //level data
	{
		if (n < 2)
		{
			const char* PropNames[2] = {
				"locationx",
				"locationy"
			};
			return PropNames[n];
		}
	}
	return "";
}

float
EditorPropRangeMin(int n, short* tiledata, float* params)
{
	if (tiledata[8] == LEVEL_DATA_STARTING_ID) //level data
	{
		if (n < 2)
		{
			float DataRanges[2] = {
				0.0f,
				0.0f
			};
			return DataRanges[n];
		}
	}
	return 0;
}

float
EditorPropRangeMax(int n, short* tiledata, float* params)
{
	if (tiledata[8] == LEVEL_DATA_STARTING_ID) //level data
	{
		if (n < 2)
		{
			float DataRanges[2] = {
				1024.0f,
				1024.0f
			};
			return DataRanges[n];
		}
	}
	return 0;
}

#define STBTE_SHOW_CUROSR
#define STBTE_MAX_PROPERTIES 8
#define STBTE_MAX_LAYERS 15
#define STBTE_MAX_TILEMAP_X 512
#define STBTE_MAX_TILEMAP_Y	 512
#define STBTE_PROP_TYPE(n,tiledata,params) EditorPropType(n,tiledata,params)
#define STBTE_PROP_NAME(n,tiledata,params) EditorPropName(n,tiledata,params)
#define STBTE_PROP_MIN(n,tiledata,params) EditorPropRangeMin(n,tiledata,params)
#define STBTE_PROP_MAX(n,tiledata,params) EditorPropRangeMin(n,tiledata,params)
#define STBTE_DRAW_RECT(x0,y0,x1,y1,color) EditorDrawRect(x0,y0,x1,y1,color)
#define STBTE_DRAW_TILE(x0,y0,id,highlight,data) EditorDrawTile(x0,y0,id,highlight,data)



//NOTE(ian): optional things to define

/*
#dfine STBTE_ALLOW_LINK(src,src_data,dest,dest_data)
#define STBTE_LINK_COLOR(src,src_data,dest,dest_data)
#define STBTE_MAX_TILEMAP_X      200   // max 4096
#define STBTE_MAX_TILEMAP_Y      200   // max 4096
#define STBTE_MAX_LAYERS         8     // max 32
#define STBTE_MAX_CATEGORIES     100
#define STBTE_UNDO_BUFFER_BYTES  (1 << 24) // 16 MB
#define STBTE_MAX_COPY           90000  // e.g. 300x300
#define STBTE_MAX_PROPERTIES     10     // max properties per tile

*/

stbte_tilemap*
EditorInit(stbte_tilemap* Map, i2 MapDim,s32 MapLayers,i2 Spacing,s32 MaxTiles, b2 Window)
{
	stbte_set_display(Window.X, Window.Y, Window.W + Window.X, Window.H + Window.Y);
	Map = stbte_create_map(MapDim.X, MapDim.Y, MapLayers, Spacing.X, Spacing.Y, MaxTiles);

	for (s32 I = BACKGROUND_STARTING_ID;
		I < BACKGROUND_STARTING_ID + NUM_BACKGROUND_TILE_TYPES;
		++I)
	{
		stbte_define_tile(Map, I, GAME_ELEMENTS_LAYER_MASK, "Static");
	}

	for (s32 I = CHEBYSHEV_WALL_STARTING_ID;
		I < CHEBYSHEV_WALL_STARTING_ID + NUM_CHEBYSHEV_WALL_TILE_TYPES;
		++I)
	{
		stbte_define_tile(Map, I, GAME_ELEMENTS_LAYER_MASK, "Static");
	}

	for (s32 I = BLOCK_STARTING_ID;
		I < BLOCK_STARTING_ID + NUM_BLOCK_TYPES;
		++I)
	{
		stbte_define_tile(Map, I, GAME_ELEMENTS_LAYER_MASK, "Movers");
	}

	for (s32 I = LEVEL_DATA_STARTING_ID;
		I < LEVEL_DATA_STARTING_ID + NUM_LEVEL_DATA_TILE_TYPES;
		++I)
	{
		stbte_define_tile(Map, I, LEVEL_DATA_LAYER_MASK, "Level Data");
	}


	stbte_define_tile(Map, PLAYER_ID, GAME_ELEMENTS_LAYER_MASK, "Movers");





	return Map;
}

void
EditorCompile(stbte_tilemap* Map)
{

}

void
EditorDrawAndUpdate(stbte_tilemap* Map, user_input* Input)
{

	
	if (LengthSq(Input->ChangeInMousePos) > 0)
	{
		stbte_mouse_move(Map, Input->MousePos.X, Input->MousePos.Y, 0, 0);
		Input->ChangeInMousePos = i2{ 0,0 };
	}

	if (Input->Actions[EDITOR_LEFT_CLICK].JustPressed)
	{
		stbte_mouse_button(Map, Input->MousePos.X, Input->MousePos.Y, 0, 1, 0, Input->Actions[SELECT].Pressed);
	}

	if (Input->Actions[EDITOR_RIGHT_CLICK].JustPressed)
	{
		stbte_mouse_button(Map, Input->MousePos.X, Input->MousePos.Y, 1, 1, 0, Input->Actions[SELECT].Pressed);
	}

	if (Input->Actions[EDITOR_LEFT_CLICK].JustReleased)
	{
		stbte_mouse_button(Map, Input->MousePos.X, Input->MousePos.Y, 0, 0, 0, Input->Actions[SELECT].Pressed);
	}

	if (Input->Actions[EDITOR_RIGHT_CLICK].JustReleased)
	{
		stbte_mouse_button(Map, Input->MousePos.X, Input->MousePos.Y, 1, 0, 0, Input->Actions[SELECT].Pressed);
	}

	
	for (int I = 11;
		I < NUM_KEY_ACTIONS;
		++I)
	{
		if (Input->Actions[I].JustPressed)
		{
			stbte_action(Map, I - 11);
		}
	}
	
	
	



	//al_clear_to_color(al_map_rgb(0, 0, 0));
	stbte_tick(Map, Input->dt);
	stbte_draw(Map);

	/*
	if (Input->Actions[EDITOR_LEFT_CLICK].JustPressed)
	{
		al_draw_filled_circle(200.0f, 200.0f, 50.0f, al_map_rgb(255, 33, 128));
	}
	else if (Input->Actions[EDITOR_LEFT_CLICK].Pressed)
	{
		al_draw_filled_circle(200.0f, 200.0f, 25.0f, al_map_rgb(255, 33, 128));
	}

	if (Input->Actions[EDITOR_RIGHT_CLICK].JustPressed)
	{
		al_draw_filled_circle(400.0f, 400.0f, 50.0f, al_map_rgb(25, 203, 118));
	}
	else if (Input->Actions[EDITOR_RIGHT_CLICK].Pressed)
	{
		al_draw_filled_circle(400.0f, 400.0f, 25.0f, al_map_rgb(25, 203, 118));
	}
	*/
	
	al_flip_display();
	
}

#define STB_TILEMAP_EDITOR_IMPLEMENTATION

#include "stb-master\stb_tilemap_editor.h"

#endif













#define MAX_UNDO_WORDS 50000
typedef struct {
	s32 Words[MAX_UNDO_WORDS];
	s32 NumEntries;
	s32 NumWords;
	s32 UndoCount;
} undo_stack;










typedef struct {
	level Level;
	undo_stack UndoStack;
	tween_object Tweens[MAX_TWEENS];
	//ALLEGRO_VERTEX Quad[6];
	r2 Screen;
	texture Window;
	texture_group TextureGroup;
	prng_state PRNG;
#ifdef EDITOR_RUNNING
	stbte_tilemap* EditorTileMap;
#endif
	i2 PreviousMove;
	v2 CameraPos;
	s32 RecentEvent;
	r32 AgainTime;
	b32 InEditor;
	r64 tSine;
	u16 SoundOffset;
}game_state;

typedef struct {
	v2 Hit;
	r32 LinePer;
	r32 RayPer;
}ray_variables;



inline b32
IsCracked(s8 Entry)
{
	b32 Result = ((Entry >= 'A' && Entry <= 'Z'));
	return Result;
}

inline b32
IsMetriclessWall(s8 Entry)
{
	b32 Result = (Entry == 's' || Entry == 'S');
	return Result;
}

inline b32
IsChebyshevWall(s8 Entry)
{
	b32 Result = (Entry == 'x' || Entry == 'X');
	return Result;
}

inline b32
IsMetriclessCrate(s8 Entry)
{
	b32 Result = (Entry == 'd' || Entry == 'D');
	return Result;
}

inline b32
IsChebyshevCrate(s8 Entry)
{
	b32 Result = (Entry == 'b' || Entry == 'B');
	return Result;
}

inline b32
IsEmpty(s8 Entry)
{
	b32 Result = (Entry == '.');
	return Result;
}

inline b32
IsPlayer(s8 Entry)
{
	b32 Result = (Entry == 'P');
	return Result;
}

inline s8
MakeCracked(s8 Entry)
{
	s8 Result = Entry;
	if (!IsCracked(Entry))
	{
		Result -= 32;
	}

	return Result;
}

inline s8
InitializeEmpty()
{
	return '.';
}

inline s8
InitializePlayer()
{
	return 'P';
}

inline s8
InitializeChebyshevWall()
{
	return 'x';
}



inline s8
InitializeMetriclessWall()
{
	return 's';
}



inline s8
InitializeChebyshevCrate()
{
	return 'b';
}



inline s8
InitializeMetriclessCrate()
{
	return 'd';
}





inline ray_variables
Ray2D(v2 Ray, v2 RayPoint, v2 LinePoint, v2 LineRay)
{
	ray_variables Variables = ray_variables{ v2{ 0.0f, 0.0f }, -1.0f,-1.0f };
	r32 RaysCross = Cross(Ray, LineRay);
	if (RaysCross != 0.0f)
	{
		r32 t = Cross(LinePoint - RayPoint, LineRay) / RaysCross;
		r32 Epsilon = 0.00001f;
		if (t >= Epsilon && t <= 1.0f)
		{
			r32 u = Cross(RayPoint - LinePoint, Ray) / -RaysCross;
			if (u >= 0.0f && u <= 1.0f)
			{
				Variables.Hit = (u * LineRay) + LinePoint;
				Variables.LinePer = u;
				Variables.RayPer = t;
			}
		}
	}
	return Variables;
}


internal r32
GetUndoWaitTime(s32 NumUndos)
{
	r32 Result = 0.0f;
	if (NumUndos < 10)
	{
		Result = 0.1f;
	}
	else if (NumUndos < 25)
	{
		Result = 0.05f;
	}
	else if (NumUndos < 50)
	{
		Result = 0.025f;
	}
	else if (NumUndos < 100)
	{
		Result = 0.0125f;
	}
	else if (NumUndos < 200)
	{
		Result = 0.00625f;
	}

	return Result;
}


internal void
PushOntoUndoStack(game_state* GameState, block* Blocks, s32 NumBlocks, undo_stack* UndoStack)
{
	s32 NumObjects = 0;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (LengthSq(Blocks[I].Move) > 0 || AreAnyBitsSet(Blocks[I].Flags,CHANGING_TO_CHEBYSHEV | CHANGING_TO_METRICLESS | CHANGING_TO_INVISIBLE))
		{
			UndoStack->Words[UndoStack->NumWords++] = I;
			UndoStack->Words[UndoStack->NumWords++] = Blocks[I].Pos.X;
			UndoStack->Words[UndoStack->NumWords++] = Blocks[I].Pos.Y;
			UndoStack->Words[UndoStack->NumWords++] = Blocks[I].Flags;
			++NumObjects;
		}
	}

	UndoStack->Words[UndoStack->NumWords++] = NumObjects;
	UndoStack->NumEntries++;

}

#define NULL_GROUP_ID -1

internal void
ResetBlocks(game_state*GameState, block*Blocks, s32 NumBlocks)
{
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		Blocks[I].Flags = EraseBits(Blocks[I].Flags, PHYSICS_FLAGS_MASK);
		Blocks[I].GroupID = NULL_GROUP_ID;
		Blocks[I].Move = i2{ 0,0 };
	}
}


internal void
UpdateUndoStack(game_state* GameState, block* Blocks, s32 NumBlocks, undo_stack* UndoStack)
{
	s32 NumObjects = UndoStack->Words[UndoStack->NumWords - 1];
	s32 NewDataStartIndex = UndoStack->NumWords - 1;
	s32 CurrentStartIndex = NewDataStartIndex - 4 * NumObjects;
	--UndoStack->NumWords;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		s32 UndoIndex = CurrentStartIndex + 4 * I;
		s32 BlockIndex = UndoStack->Words[UndoIndex];
		if (LengthSq(Blocks[I].Move) > 0 
			|| AreAnyBitsSet(Blocks[I].Flags, CHANGING_TO_CHEBYSHEV | CHANGING_TO_METRICLESS | CHANGING_TO_INVISIBLE))
		{
			b32 InCurrentData = false;
			for (s32 J = CurrentStartIndex;
				J < NewDataStartIndex;
				J += 4)
			{
				if (UndoStack->Words[J] == I)
				{
					InCurrentData = true;
					break;
				}
			}

			if (!InCurrentData)
			{
				UndoStack->Words[UndoStack->NumWords++] = I;
				UndoStack->Words[UndoStack->NumWords++] = Blocks[I].Pos.X;
				UndoStack->Words[UndoStack->NumWords++] = Blocks[I].Pos.Y;
				UndoStack->Words[UndoStack->NumWords++] = Blocks[I].Flags;
				++NumObjects;
			}
		}
	}

	UndoStack->Words[UndoStack->NumWords++] = NumObjects;
}

internal void
UndoTurn(game_state* GameState, block* Blocks, s32 NumBlocks, undo_stack* UndoStack)
{
	s32 NumObjects = UndoStack->Words[UndoStack->NumWords - 1];
	s32 StartIndex = UndoStack->NumWords - 5;
	for (s32 I = 0;
		I < NumObjects;
		++I)
	{
		s32 UndoIndex = StartIndex - 4 * I;
		s32 ObjectIndex = UndoStack->Words[UndoIndex];
		Blocks[ObjectIndex].Pos.X = UndoStack->Words[UndoIndex + 1];
		Blocks[ObjectIndex].Pos.Y = UndoStack->Words[UndoIndex + 2];
		Blocks[ObjectIndex].Flags = UndoStack->Words[UndoIndex + 3];
		Blocks[ObjectIndex].Rect.P = V2(Blocks[ObjectIndex].Pos);
	}

	--UndoStack->NumEntries;
	UndoStack->NumWords -= 4 * NumObjects + 1;

	//TODO(ian): move this outside this function!!!
	for (s32 I = 0;
		I < MAX_TWEENS;
		++I)
	{
		GameState->Tweens[I].Type = TYPE_NULL;
	}

	ResetBlocks(GameState, Blocks, NumBlocks);
}


internal void
RestartTurn(s8 *Grid, i2 LevelSize, s32* PreviousState, u32*TotalStateBytes, u32* TotalStateEntries)
{

}


internal b32
AlreadyTagged(s32* Indices, s32 NumIndices, s32 Index)
{
	b32 Checked = false;
	for (u32 K = 0;
		K < NumIndices;
		++K)
	{
		if (Index == Indices[K])
		{
			Checked = true;
			break;
		}
	}
	return Checked;
}

internal s32
FindIndex(s32* Indices, s32 NumIndices, s32 Index)
{
	s32 Result = -1;
	for (s32 K = 0;
		K < NumIndices;
		++K)
	{
		if (Index == Indices[K])
		{
			Result = K;
			break;
		}
	}
	return Result;
}








/*

enum entity_flags {
EMPTY_FLAG = 0,
CONNECTED_TO_CHEBYSHEV = 1, //first 6 are physics flags
SURROUNDED_BY_METRICLESS = 2,
SOMETHING_UNDERNEATH = 4,
FALLING = 8,
CHANGING_TO_CHEBYSHEV = 16,
CHANGING_TO_METRICLESS = 32,
PLAYER_FLAG = 64, //next 7 flags are types
CHEBYSHEV_FLAG = 128,
METRICLESS_FLAG = 256,
SPECIAL_FLAG = 512,
SPECIAL_MAKER_FLAG = 1024,
HOLE_FLAG = 2048,
SWAPPER_FLAG = 4096,
DIAGONAL_MOVEMENT_ACTIVATED = 8192 //Is this needed?
};
*/




internal void
GroupConnectedBlocks(game_state* GameState, block* Blocks, s32 NumBlocks)
{
	s32 GroupID = 0;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (Blocks[I].GroupID == NULL_GROUP_ID)
		{
			if (AreBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG))
			{
				Blocks[I].GroupID = GroupID++;

				//TODO(ian): this algorithm increases by O(n^2); is there a better way to do this?
				b32 PatternFound;
				do {
					PatternFound = false;
					for (s32 J = 0;
						J < NumBlocks;
						++J)
					{
						if (Blocks[J].GroupID == Blocks[I].GroupID  && AreBitsSet(Blocks[J].Flags, CHEBYSHEV_FLAG))
						{
							for (s32 K = 0;
								K < NumBlocks;
								++K)
							{
								if (Blocks[K].GroupID == NULL_GROUP_ID && AreBitsSet(Blocks[K].Flags, CHEBYSHEV_FLAG) && CDistance(Blocks[J].Pos, Blocks[K].Pos) == 1)
								{
									Blocks[K].GroupID = Blocks[I].GroupID;
									PatternFound = true;
								}
							}
						}
					}

				} while (PatternFound);
			}
			else if (AreBitsSet(Blocks[I].Flags, METRICLESS_FLAG))
			{
				//TODO(ian): should something happen here?
			}
		}
	}
}



internal b32
AreBlocksChangingType(game_state* GameState, s8*Level, i2 LevelSize,block* Blocks, s32 NumBlocks)
{

	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		for (s32 J = -1;
			J < 2;
			++J)
		{
			for (s32 K = -1;
				K < 2;
				++K)
			{
				s8 Field = Level[(Blocks[I].Pos.Y + J)*LevelSize.X + Blocks[I].Pos.X + K];
				if (IsChebyshevWall(Field) || IsChebyshevCrate(Field)) //NOTE(ian): make sure that all immutable chebyshevcrates are connected to chebyshev walls
				{
					Blocks[I].Flags = SetBits(Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV);
				}
				else if (IsMetriclessWall(Field))
				{
					Blocks[I].Flags = SetBits(Blocks[I].Flags, SURROUNDED_BY_METRICLESS);
				}
			}
		}
	}


	s32 Indices[MAX_BLOCKS_PER_LEVEL];
	s32 NumIndices = 0;

	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (AreBitsSet(Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV | CHEBYSHEV_FLAG) && !AlreadyTagged(Indices,NumIndices,Blocks[I].GroupID))
		{
			s32 ConnectedGroupID = Blocks[I].GroupID;
			Indices[NumIndices++] = ConnectedGroupID;
			for (s32 J = 0;
				J < NumBlocks;
				++J)
			{
				if (Blocks[J].GroupID == ConnectedGroupID)
				{
					Blocks[J].Flags = SetBits(Blocks[J].Flags, CONNECTED_TO_CHEBYSHEV);
				}
			}

		}
	}

	b32 PatternFound;
	do {
		PatternFound = false;
		for (s32 I = 0;
			I < NumBlocks;
			++I)
		{
			if (!AreBitsSet((u32)Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV) && AreAnyBitsSet(Blocks[I].Flags, METRICLESS_FLAG | PLAYER_FLAG))
			{
				for (s32 J = 0;
					J < NumBlocks;
					++J)
				{
					if (CDistance(Blocks[I].Pos, Blocks[J].Pos) == 1 && AreBitsSet(Blocks[J].Flags,CONNECTED_TO_CHEBYSHEV | CHEBYSHEV_FLAG))
					{
						Blocks[I].Flags = SetBits(Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV);
						PatternFound = true;
						break;
					}
				}
			}
		}
	} while (PatternFound);


	b32 Changing = false;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (AreBitsSet(Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV | METRICLESS_FLAG))
		{
			Blocks[I].Flags = SetBits(Blocks[I].Flags, CHANGING_TO_CHEBYSHEV);
			Changing = true;
		}
		else if (AreBitsSet(Blocks[I].Flags, SURROUNDED_BY_METRICLESS | CHEBYSHEV_FLAG ) && !AreBitsSet(Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV))
		{
			Blocks[I].Flags = SetBits(Blocks[I].Flags, CHANGING_TO_METRICLESS);
			Changing = true;
		}
	}
	
	return Changing;
}



internal b32
AreBlocksgFalling(game_state* GameState, s8*Level, i2 LevelSize, block* Blocks, s32 NumBlocks)
{
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		s8 Field = Level[(Blocks[I].Pos.Y + 1)*LevelSize.X + Blocks[I].Pos.X];
		if (!IsEmpty(Field))
		{
			Blocks[I].Flags = SetBits(Blocks[I].Flags, SOMETHING_UNDERNEATH);
		}

		for (s32 J = 0;
			J < NumBlocks;
			++J)
		{
			if (Blocks[I].Pos.Y + 1 == Blocks[J].Pos.Y && Blocks[I].Pos.X == Blocks[J].Pos.X
				&& (!AreBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG) || !AreBitsSet(Blocks[J].Flags, CHEBYSHEV_FLAG)))
				//&& (!AreBitsSet(Blocks[J].Flags,INVISIBLE_FLAG) || AreBitsSet(Blocks[I].Flags, INVISIBLE_FLAG)))
			{
				Blocks[I].Flags = SetBits(Blocks[I].Flags, SOMETHING_UNDERNEATH);
			}
		}
	}


	//NOTE(ian): perpetuate something underneath
	s32 Indices[MAX_BLOCKS_PER_LEVEL];
	s32 NumIndices = 0;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (AreBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG | SOMETHING_UNDERNEATH) && !AlreadyTagged(Indices,NumIndices,Blocks[I].GroupID))
		{
			s32 ConnectedGroupID = Blocks[I].GroupID;
			Indices[NumIndices++] = ConnectedGroupID;
			for (s32 J = 0;
				J < NumBlocks;
				++J)
			{
				if (Blocks[J].GroupID == ConnectedGroupID)
				{
					Blocks[J].Flags = SetBits(Blocks[J].Flags, SOMETHING_UNDERNEATH);
				}
			}
		}
	}

	b32 Falling = false;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (!AreAnyBitsSet(Blocks[I].Flags, SOMETHING_UNDERNEATH | CONNECTED_TO_CHEBYSHEV))
		{
			Blocks[I].Move = i2{ 0,1 };
			Falling = true;
		}
	}

	return Falling;
}






//NOTE(ian): the 0 entry in the blocks array should always be the player!!!!
internal b32
SetUpPlayerMove(game_state* GameState, s8* Level, i2 LevelSize, block* Blocks, s32 NumBlocks, i2 Move,s32 Index)
{
	b32 HasMoved = false;
	i2 AdjacentPos = Blocks[Index].Pos + Move;
	s32 AdjacentIndex = (AdjacentPos.Y) * LevelSize.X + (AdjacentPos.X);
	s32 AdjacentBlockIndex = -1;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (Blocks[I].Pos == AdjacentPos)// && !AreBitsSet(Blocks[I].Flags,INVISIBLE_FLAG))
		{
			AdjacentBlockIndex = I;
		}

		Blocks[I].Move = i2{ 0,0 };
		//Blocks[I].Flags = EraseBits(Blocks[I].Flags, MOVING | STOPPED);
	}

	b32 MoreThanOneInGroup = false;
	s32 GroupID = Blocks[Index].GroupID;

	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (Blocks[I].GroupID == GroupID && I != Index)
		{
			MoreThanOneInGroup = true;
			break;
		}

	}


	Blocks[Index].Move = Move;

	s8 Field = Level[AdjacentIndex];
	if (IsChebyshevWall(Field) || IsMetriclessWall(Field)
		|| IsChebyshevCrate(Field) || IsMetriclessCrate(Field)) //#1 Player against immutable part of level
	{
		HasMoved = false;
	}
	else if ((AdjacentBlockIndex != -1 && AreAnyBitsSet(Blocks[AdjacentBlockIndex].Flags, CHEBYSHEV_FLAG | METRICLESS_FLAG)) 
		|| (Blocks[Index].GroupID != NULL_GROUP_ID && MoreThanOneInGroup)) // #5  player pushes block
	{
		Blocks[AdjacentBlockIndex].Move = Move;
		//Blocks[AdjacentBlockIndex].Flags = SetBits(Blocks[AdjacentBlockIndex].Flags, MOVING);
			

		//NOTE(ian): perpetrate move
		s32 Indices[MAX_BLOCKS_PER_LEVEL];
		s32 NumIndices = 0;
		s32 NumIterations = 0;
		b32 PatternFound;
		do {
			PatternFound = false;
			for (s32 I = 0;
				I < NumBlocks;
				++I)
			{
				if (LengthSq(Blocks[I].Move) > 0 && !AlreadyTagged(Indices,NumIndices,I))
				{
					Indices[NumIndices++] = I;
					if (AreBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG))
					{
						for (s32 J = 0;
							J < NumBlocks;
							++J)
						{
							if (CDistance(Blocks[I].Pos, Blocks[J].Pos) == 1 && LengthSq(Blocks[J].Move) == 0)
							{
								if (AreBitsSet(Blocks[J].Flags, CHEBYSHEV_FLAG))
								{
									Blocks[J].Move = Move;
									PatternFound = true;
								}
								else if (Blocks[I].Pos + Move == Blocks[J].Pos && AreBitsSet(Blocks[J].Flags, METRICLESS_FLAG))
								{
									Blocks[J].Move = Move;
									PatternFound = true;
								}
								/*
								else if (Blocks[I].Pos + Move == Blocks[J].Pos && AreBitsSet(Blocks[J].Flags, PLAYER_FLAG))
								{
									Blocks[J].Move = Move;
									PatternFound = true;
								}
								*/
							}
						}
					}
					else if (AreBitsSet(Blocks[I].Flags, METRICLESS_FLAG))
					{
						for (s32 J = 0;
							J < NumBlocks;
							++J)
						{
							if (Blocks[I].Pos + Move == Blocks[J].Pos && LengthSq(Blocks[J].Move) == 0)
							{
								if (AreAnyBitsSet(Blocks[J].Flags, CHEBYSHEV_FLAG | METRICLESS_FLAG))// | PLAYER_FLAG))
								{
									Blocks[J].Move = Move;
									PatternFound = true;
								}
							}
						}
					}
					/*
					else if (AreBitsSet(Blocks[I].Flags, PLAYER_FLAG))
					{
						for (s32 J = 0;
							J < NumBlocks;
							++J)
						{
							if (Blocks[I].Pos + Move == Blocks[J].Pos && LengthSq(Blocks[J].Move) == 0)
							{
								if (AreAnyBitsSet(Blocks[J].Flags, CHEBYSHEV_FLAG | METRICLESS_FLAG))
								{
									Blocks[J].Move = Move;
									PatternFound = true;
								}
							}
						}
					}
					*/
				}

			}
			Assert(++NumIterations < 100);
		} while (PatternFound);




		//NOTE(ian): detect if stopped
		for (s32 I = 0;
			I < NumBlocks;
			++I)
		{
			if (LengthSq(Blocks[I].Move) > 0 && AreAnyBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG | METRICLESS_FLAG))
			{
				s32 MovedIntoBlockIndex = (Blocks[I].Pos.Y + Move.Y)*LevelSize.X + (Blocks[I].Pos.X + Move.X);
				if (IsChebyshevWall(Level[MovedIntoBlockIndex]) || IsMetriclessWall(Level[MovedIntoBlockIndex])
					|| IsChebyshevCrate(Level[MovedIntoBlockIndex]) || IsMetriclessCrate(Level[MovedIntoBlockIndex]))
				{
					Blocks[I].Move = i2{ 0,0 };
				}
			}
			if (AreBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG))
			{
				b32 NearImmovable = false;
				for (s32 Y = -1;
					Y < 2;
					++Y)
				{
					for (s32 X = -1;
						X < 2;
						++X)
					{
						if (IsChebyshevCrate(Level[(Blocks[I].Pos.Y + Y)*LevelSize.X + (Blocks[I].Pos.X + X)]))
						{
							Blocks[I].Move = i2{ 0,0 };
							NearImmovable = true;
							break;
						}
					}
					if (NearImmovable)
					{
						break;
					}

				}
			}

			//TODO(ian): get rid of invisible flag
			//TODO(ian): check whether allowing chebyshev and metricless blocks to push the player breaks or weakens puzzles: answer it breaks a few
			//NOTE(ian): if block tries to push player block
			//TODO(ian): this rule is arbitrary and a relic of another version of the game; should i get rid of it in order to make the rules simpler? I'm thinking yes at the moment
			
			/*
			if (AreAnyBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG | METRICLESS_FLAG))
			{
				for (s32 J = 0;
					J < NumBlocks;
					++J)
				{
					if (Blocks[I].Pos + Blocks[I].Move == Blocks[J].Pos
						&& AreBitsSet(Blocks[J].Flags, PLAYER_FLAG))// && !AreBitsSet(Blocks[J].Flags,INVISIBLE_FLAG))
					{
						Blocks[I].Move = i2{ 0,0 };
					}
				}

			}
			*/
			
				
				
		}


		//NOTE(ian): perpetrate stopped
		NumIndices = 0;
		do {
			PatternFound = false;
			for (s32 I = 0;
				I < NumBlocks;
				++I)
			{
				if (LengthSq(Blocks[I].Move) == 0 && !AlreadyTagged(Indices,NumIndices,I))
				{
					Indices[NumIndices++] = I;
					if (AreBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG))
					{
						for (s32 J = 0;
							J < NumBlocks;
							++J)
						{
							if (CDistance(Blocks[I].Pos, Blocks[J].Pos) == 1 && LengthSq(Blocks[J].Move) > 0)
							{
								if (AreBitsSet(Blocks[J].Flags, CHEBYSHEV_FLAG))
								{
									Blocks[J].Move = i2{ 0,0 };
									PatternFound = true;
								}
								else if (Blocks[I].Pos == Blocks[J].Pos + Move && AreBitsSet(Blocks[J].Flags, METRICLESS_FLAG))
								{
									Blocks[J].Move = i2{ 0,0 };
									PatternFound = true;
								}
							}
						}
					}
					else if (AreBitsSet(Blocks[I].Flags, METRICLESS_FLAG))
					{
						for (s32 J = 0;
							J < NumBlocks;
							++J)
						{
							if (Blocks[I].Pos == Blocks[J].Pos + Move && LengthSq(Blocks[J].Move) > 0)
							{
								if (AreAnyBitsSet(Blocks[J].Flags, CHEBYSHEV_FLAG | METRICLESS_FLAG))
								{
									Blocks[J].Move = i2{ 0,0 };
									PatternFound = true;
								}
							}
						}
					}
				}

			}
			Assert(++NumIterations < 100);
		} while (PatternFound);

		HasMoved = (LengthSq(Blocks[AdjacentBlockIndex].Move) > 0);
	}
	else if (IsEmpty(Field) && AdjacentBlockIndex == -1) // #2 Player againts empty square
	{
		b32 IsSticky = false;
		for (s32 Y = -1;
			Y < 2;
			++Y)
		{
			for (s32 X = -1;
				X < 2;
				++X)
			{
				s32 Index = (AdjacentPos.Y + Y)*LevelSize.X + (AdjacentPos.X + X);
				if (IsChebyshevCrate(Level[Index]) || IsChebyshevWall(Level[Index]))
				{
					IsSticky = true;
					break;
				}
			}
			if (IsSticky)
			{
				break;
			}
		}


		if (!IsSticky)
		{
			for (s32 I = 0;
				I < NumBlocks;
				++I)
			{
				if (CDistance(AdjacentPos, Blocks[I].Pos) == 1 && AreBitsSet(Blocks[I].Flags, CHEBYSHEV_FLAG | CONNECTED_TO_CHEBYSHEV))
				{
					IsSticky = true;
					break;
				}
			}
		}

		HasMoved = IsSticky;
	}

	return HasMoved;
}



internal b32
ArePlayerBlocksDisappearing(game_state* GameState, s8* Level, i2 LevelSize, block* Blocks, s32 NumBlocks)
{

	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (AreBitsSet(Blocks[I].Flags, PLAYER_FLAG))
		{
			Blocks[I].Flags = EraseBits(Blocks[I].Flags, CHANGING_TO_INVISIBLE);
		}
	}



	b32 HasChanged = false;
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		if (AreBitsSet(Blocks[I].Flags, PLAYER_FLAG))
		{

			b32 CanMove = false;
			for (s32 A = 0;
				A < CTAUINT;
				A += 2)
			{



				i2 Move = CEuler(A);
				if (SetUpPlayerMove(GameState, Level, LevelSize, Blocks, NumBlocks, Move, I))
				{
					CanMove = true;
					break;
				}
			}

			if (CanMove && AreBitsSet(Blocks[I].Flags,INVISIBLE_FLAG))
			{
				HasChanged = true;
				//Blocks[I].Flags = EraseBits(Blocks[I].Flags, INVISIBLE_FLAG);
				Blocks[I].Flags = SetBits(Blocks[I].Flags, CHANGING_TO_INVISIBLE);
			}
			else if (!CanMove && !AreBitsSet(Blocks[I].Flags, INVISIBLE_FLAG))
			{
				HasChanged = true;
				//Blocks[I].Flags = SetBits(Blocks[I].Flags, INVISIBLE_FLAG);
				Blocks[I].Flags = SetBits(Blocks[I].Flags, CHANGING_TO_INVISIBLE);
			}


		}
	}

	return HasChanged;
}


/*
enum event_type {
NO_EVENT,
MOVED_LATERALLY,
MOVED_DIAGONALLY,
CRATE_CHANGED_STATE,
SINGLE_STEP_FALL,
UNDO_HAPPENED
};
*/

internal void
PerformMove(game_state* GameState, block* Blocks, s32 NumBlocks, s32 Event)
{
	if (Event == CRATE_CHANGED_STATE)
	{
		for (s32 I = 0;
			I < NumBlocks;
			++I)
		{
			if (AreBitsSet(Blocks[I].Flags, CHANGING_TO_CHEBYSHEV))
			{
				
				Blocks[I].Flags = SetBits(Blocks[I].Flags, CHEBYSHEV_FLAG);
				Blocks[I].Flags = EraseBits(Blocks[I].Flags, METRICLESS_FLAG);
			}
			else if (AreBitsSet(Blocks[I].Flags, CHANGING_TO_METRICLESS))
			{
				Blocks[I].Flags = EraseBits(Blocks[I].Flags, CHEBYSHEV_FLAG);
				Blocks[I].Flags = SetBits(Blocks[I].Flags, METRICLESS_FLAG);
			}
		}
	}
	else if(Event == INVISIBLE_HAPPENED)
	{
		for (s32 I = 0;
			I < NumBlocks;
			++I)
		{
			if (AreBitsSet(Blocks[I].Flags, CHANGING_TO_INVISIBLE))
			{
				if (AreBitsSet(Blocks[I].Flags, INVISIBLE_FLAG))
				{
					Blocks[I].Flags = EraseBits(Blocks[I].Flags, INVISIBLE_FLAG);
				}
				else
				{
					Blocks[I].Flags = SetBits(Blocks[I].Flags, INVISIBLE_FLAG);
				}
			}
		}
	}
	else
	{
		for (s32 I = 0;
			I < NumBlocks;
			++I)
		{
			if (LengthSq(Blocks[I].Move) > 0)
			{
				Blocks[I].Pos = Blocks[I].Pos + Blocks[I].Move;
				Blocks[I].Rect.P = V2(Blocks[I].Pos);
			}
		}
	}
}



internal r32
GetEventWaitTime(u32 Event)
{
	r32 Result = 0.0f;

	if (Event == NO_EVENT)
	{

	}
	else if (Event == MOVED_LATERALLY)
	{
		Result = 10.0f / 60.0f;
	}
	else if (Event == MOVED_DIAGONALLY)
	{
		Result = 14.14f / 60.0f;
	}
	else if (Event == SINGLE_STEP_FALL)
	{
		Result = 9.0f / 60.0f;
	}
	else if (Event == CRATE_CHANGED_STATE)
	{
		Result = 2.0f / 60.0f;
	}
	else if (Event == INVISIBLE_HAPPENED)
	{
		Result = 8.0f / 60.0f;
	}

	return Result;
}

internal b32
ExecuteTurn(game_state* GameState, s8*Level,i2 LevelSize, block* Blocks,s32 NumBlocks, i2 PrimaryMove, i2 SecondaryMove)
{

	i2 Move = i2{ 0,0 };
	u32 Event = NO_EVENT;
	s32 Indices[100];
	s32 NumIndices = 0;
	GameState->PreviousMove = i2{ 0,0 };



	ResetBlocks(GameState, Blocks, NumBlocks);
	GroupConnectedBlocks(GameState, Blocks, NumBlocks);

	if (AreBlocksChangingType(GameState,Level,LevelSize,Blocks,NumBlocks))
	{
		Event = CRATE_CHANGED_STATE;
	}
	else if (AreBlocksgFalling(GameState,Level,LevelSize,Blocks,NumBlocks))
	{
		Event = SINGLE_STEP_FALL;
		Move = i2{ 0,-1 };
	}
	/*
	else if (ArePlayerBlocksDisappearing(GameState, Level, LevelSize, Blocks, NumBlocks))
	{
		Event = INVISIBLE_HAPPENED;
	}
	*/
	else
	{
		b32 HasPrimaryMove = (LengthSq(PrimaryMove) > 0);
		b32 HasSecondaryMove = (LengthSq(SecondaryMove) > 0);
		b32 HasCombinedMove = (LengthSq(PrimaryMove + SecondaryMove) > 0);



		if (HasPrimaryMove && !HasSecondaryMove)
		{
			if (SetUpPlayerMove(GameState, Level, LevelSize, Blocks, NumBlocks, PrimaryMove,0))
			{
				Event = MOVED_LATERALLY;
			}
		}
		else if (HasPrimaryMove && HasSecondaryMove && HasCombinedMove)
		{
			if (SetUpPlayerMove(GameState, Level, LevelSize, Blocks, NumBlocks, PrimaryMove,0))
			{
				Event = MOVED_LATERALLY;
			}
			else if (SetUpPlayerMove(GameState, Level, LevelSize, Blocks, NumBlocks, PrimaryMove + SecondaryMove,0))
			{
				Event = MOVED_DIAGONALLY;
			}
			else if (SetUpPlayerMove(GameState, Level, LevelSize, Blocks, NumBlocks, SecondaryMove,0))
			{
				Event = MOVED_LATERALLY;
			}
			else
			{

			}
		}
		else if (HasPrimaryMove && HasSecondaryMove && !HasCombinedMove)
		{
			if (SetUpPlayerMove(GameState, Level, LevelSize, Blocks, NumBlocks, PrimaryMove,0))
			{
				Event = MOVED_LATERALLY;
			}
			else if (SetUpPlayerMove(GameState, Level, LevelSize, Blocks, NumBlocks, SecondaryMove,0))
			{
				Event = MOVED_LATERALLY;
			}
			else
			{

			}

		}
	}

	if (Event != NO_EVENT)
	{
		if (Event != SINGLE_STEP_FALL && Event != CRATE_CHANGED_STATE && Event != INVISIBLE_HAPPENED)
		{
			PushOntoUndoStack(GameState, Blocks, NumBlocks, &GameState->UndoStack);
		}
		else
		{
			UpdateUndoStack(GameState, Blocks, NumBlocks, &GameState->UndoStack);
		}



		if (Event == CRATE_CHANGED_STATE || Event == INVISIBLE_HAPPENED || Event == MOVED_DIAGONALLY)
		{
			PerformMove(GameState, Blocks, NumBlocks, Event);
		}
		else
		{
			//PerformMove(GameState, Blocks, NumBlocks, Event);
			
			for (s32 I = 0;
				I < NumBlocks;
				++I)
			{
				if (LengthSq(Blocks[I].Move) > 0)
				{
					AddTweenV2(GameState->Tweens, &Blocks[I].Rect.P, V2(Blocks[I].Pos), 
						GetEventWaitTime(Event), V2(Blocks[I].Pos + Blocks[I].Move));
				}
			}
			
		
		}
	}

	return Event;
}





internal void
UpdateCamera(game_state* GameState)
{





	v2 NewScreenP = 0.9f*GameState->Screen.P + 0.1f * (GameState->Level.Mutables[0].Rect.P + GameState->Level.Mutables[0].Rect.Size*0.5f - GameState->Screen.Size*0.5f);
	v2 Diff = NewScreenP - GameState->Screen.P;
	
	r2 LevelRect = R2(i2{ 0,0 }, GameState->Level.LevelSize);
	LevelRect.Size = LevelRect.Size - GameState->Screen.Size;
	//NOTE(ian): this is for the newline characters at the right side of the level
	LevelRect.Size.X -= 1.0f;

	for (s32 BitMask = 3;
		BitMask >= 0;
		--BitMask)
	{
		v2 TestingDiff = v2{ 0.0f,0.0f };
		if ((BitMask & 1) == 1)
		{
			TestingDiff.X = Diff.X;
		}

		if ((BitMask & 2) == 2)
		{
			TestingDiff.Y = Diff.Y;
		}
		v2 TestingScreenP = GameState->Screen.P + TestingDiff;

		if (InsideRect(LevelRect, TestingScreenP))
		{
			NewScreenP = TestingScreenP;
			Diff = TestingDiff;
			break;
		}
	}

	if(!InsideRect(LevelRect,NewScreenP))
	{
		r32 Epsilon = 0.00;
		if (NewScreenP.X < LevelRect.X)
		{
			NewScreenP.X = LevelRect.X;
		}
		else if (NewScreenP.X >= LevelRect.X + LevelRect.W)
		{
			NewScreenP.X = LevelRect.X + LevelRect.W - Epsilon;
		}

		if (NewScreenP.Y < LevelRect.Y)
		{
			NewScreenP.Y = LevelRect.Y;
		}
		else if (NewScreenP.Y >= LevelRect.Y + LevelRect.H)
		{
			NewScreenP.Y = LevelRect.Y + LevelRect.H - Epsilon;
		}


		Diff = NewScreenP - GameState->Screen.P;
	}

	if (LengthSq(Diff) > 0.001f)
	{

		GameState->Screen.P = GameState->Screen.P + Diff;
	}
	

}




internal void
Render(texture *Window, game_state* GameState)
{



	b2 CameraBox = B2(GameState->Screen);


	CameraBox.Size = CameraBox.Size + I2(32, 18);
	CameraBox.P = CameraBox.P - I2(32, 18);

	
	CameraBox.X = Max(0, CameraBox.X-2);
	CameraBox.Y = Max(0, CameraBox.Y-2);
	CameraBox.W = Min(CameraBox.W+4,GameState->Level.LevelSize.X-CameraBox.X);
	CameraBox.H = Min(CameraBox.H+4,GameState->Level.LevelSize.Y-CameraBox.Y);

	/*
	ALLEGRO_TRANSFORM Transform;

	

	/*
	enum bitmap_type {
	EMPTY_TEXTURE,
	GRID_TEXTURE,
	PLAYER_TEXTURE,
	CHEBYSHEV_WALL_TEXTURE,
	METRICLESS_WALL_TEXTURE,
	CHEBYSHEV_BLOCK_TEXTURE,
	METRICLESS_BLOCK_TEXTURE
};
typedef struct {
ALLEGRO_BITMAP* Bitmap;
ALLEGRO_COLOR Tint;
r2 Region;
r2 Rect;
v2 Center;
r32 Angle;
s32 Flags;
}texture;
	*/

	
	al_clear_to_color(al_map_rgb_f(0,0,0));
	//al_clear_depth_buffer(1);


	ALLEGRO_TRANSFORM Transform;
	v2 TempScale = v2{ 1.0f,1.0f };
	al_build_transform(&Transform, -GameState->Screen.X*32.0f, -GameState->Screen.Y*32.0f, TempScale.X, TempScale.Y, 0.0f);
	al_use_transform(&Transform);
	
	
	al_hold_bitmap_drawing(true);
	
	

	

	for (s32 Y = CameraBox.Y + CameraBox.H - 1;
		Y >= CameraBox.Y;
		--Y)
	{
		for (s32 X = CameraBox.X;
			X < CameraBox.X + CameraBox.W;
			++X)
		{
			s8 Field = GameState->Level.Immutables[Y*GameState->Level.LevelSize.X + X];
			s32 TextureIndex = BLANK_ID;
			if (IsChebyshevWall(Field))
			{
				TextureIndex = CHEBYSHEV_WALL_ID;
				
			}
			else if (IsMetriclessWall(Field))
			{
				TextureIndex = METRICLESS_WALL_ID;
				
			}

			GameState->TextureGroup[TextureIndex].Rect.P = V2(X, Y);
			if (TextureIndex == BLANK_ID)
			{
				r32 Dist = TDistance(GameState->TextureGroup[TextureIndex].Rect.P, RectCenter(GameState->Screen)) / 20.0f;
				Dist = 1.0f - Dist;
				Dist *= Dist;

				GameState->TextureGroup[TextureIndex].Tint = al_map_rgba_f(1, 1, 1, Dist);
			}
			
			DrawRect(GameState->TextureGroup[TextureIndex]);
		}
	}

	for (s32 I = 0;
		I < GameState->Level.NumMutables;
		++I)
	{
		if (Intersects(CameraBox, B2(GameState->Level.Mutables[I].Pos, i2{ 1,1 })))
		{
			s32 TextureIndex = BLANK_ID;
			if (AreBitsSet(GameState->Level.Mutables[I].Flags, CHEBYSHEV_FLAG))
			{
				TextureIndex = CHEBYSHEV_BLOCK_ID;
			}
			else if (AreBitsSet(GameState->Level.Mutables[I].Flags, METRICLESS_FLAG))
			{
				TextureIndex = METRICLESS_BLOCK_ID;
			}
			else if (AreBitsSet(GameState->Level.Mutables[I].Flags, PLAYER_FLAG))
			{
				TextureIndex = PLAYER_ID;
			}
				
			if (TextureIndex != BLANK_ID)
			{
				GameState->TextureGroup[TextureIndex].Rect.P = GameState->Level.Mutables[I].Rect.P;

				//GameState->TextureGroup[TextureIndex].Rect.Y = VerticalFlip(R2(GameState->TextureGroup[TextureIndex].Rect.P, v2{ 1.0f,1.0f }), GameState->Screen.Y + GameState->Screen.H*0.5f);

				DrawRect(GameState->TextureGroup[TextureIndex]);
				//DrawSpecialQuad(GameState, R2(CameraBox), LightP, GameplayZ, LightZ, WallZ, TextureIndex);
			}
		}
	}

	al_hold_bitmap_drawing(false);


	al_flip_display();

	/*
	al_identity_transform(&Transform);

	r32 ZValue = GameState->Window.Rect.W*0.5f / Tangent(TAU32 / 8.0f);

	al_perspective_transform(&Transform, 0.0f, 0.0f, ZValue, GameState->Window.Rect.W, GameState->Window.Rect.H, 2000.0f);
	//al_perspective_transform(&Transform, 0.0f, 0.0f, ZValue, 800, 450, 2000);
	al_use_projection_transform(&Transform);

	ALLEGRO_TRANSFORM Camera;
	al_build_camera_transform(&Camera, -GameState->Screen.X, -GameState->Screen.Y, ZValue, 0, 0, 0, 0, 1, 0);
	al_use_transform(&Camera);


	DrawCuboid(GameState, GameState->Screen, v3{ 100,100,0 }, v3{ 100,100,-100 }, GameState->TextureGroup[METRICLESS_BLOCK_ID]);
	DrawCuboid(GameState, GameState->Screen, v3{ 200,200,0 }, v3{ 200,200,-200 }, GameState->TextureGroup[METRICLESS_BLOCK_ID]);
	*/
	
}


internal void
GameUpdateAndRender(texture *Window, game_state *GameState, user_input *Input)
{

	if (GameState->InEditor)
	{
#ifdef EDITOR_RUNNING
		EditorDrawAndUpdate(GameState->EditorTileMap, Input);
#endif
		if (Input->Actions[EDITOR_RUN].JustPressed)
		{
			GameState->InEditor = false;


		}
	}
	else
	{
		if (Input->Actions[EDITOR_RUN].JustPressed)
		{
			GameState->InEditor = true;
		}
		input_scan_data Pressed = input_scan_data{ i2{ 0,0 },0 };
		input_scan_data JustPressed = input_scan_data{ i2{ 0,0 },0 };
		input_scan_data Held = input_scan_data{ i2{ 0,0 },0 };

		for (s32 I = 0;
			I < CTAUINT;
			I += 2)
		{
			if (Input->Actions[I].Pressed)
			{
				i2 InputtedMove = CEuler(I);
				InputtedMove.Y *= -1;
				Pressed.Move = Pressed.Move + InputtedMove;
				++Pressed.Num;
				if (Input->Actions[I].JustPressed)
				{
					i2 InputtedMove = CEuler(I);
					InputtedMove.Y *= -1;
					JustPressed.Move = JustPressed.Move + InputtedMove;
					++JustPressed.Num;
				}
				else
				{
					i2 InputtedMove = CEuler(I);
					InputtedMove.Y *= -1;
					Held.Move = Held.Move + InputtedMove;
					++Held.Num;
				}
			}
		}


		if (Pressed.Num == 0)
		{
			Input->HasInputtedMove = false;
			Input->PrimaryInputtedMove = i2{ 0,0 };
			Input->SecondaryInputtedMove = i2{ 0,0 };
		}
		else
		{
			Input->HasInputtedMove = true;
			if (JustPressed.Num == 0 && Held.Num == 1)
			{
				Input->PrimaryInputtedMove = Held.Move;
				Input->SecondaryInputtedMove = i2{ 0,0 };
			}
			else if (JustPressed.Num == 1 && Held.Num == 0)
			{
				Input->PrimaryInputtedMove = JustPressed.Move;
				Input->SecondaryInputtedMove = i2{ 0,0 };
			}
			else if (JustPressed.Num == 1 && Held.Num == 1)
			{
				Input->PrimaryInputtedMove = JustPressed.Move;
				Input->SecondaryInputtedMove = Held.Move;
			}
			else if (JustPressed.Num == 0 && Held.Num == 2)
			{
				r32 MaxTime = 0.0f;
				for (s32 I = 0;
					I < CTAUINT;
					I += 2)
				{
					if (Input->Actions[I].Pressed)
					{
						if (Input->Actions[I].Time > MaxTime)
						{
							MaxTime = Input->Actions[I].Time;
							Input->SecondaryInputtedMove = Input->PrimaryInputtedMove;
							i2 InputtedMove = CEuler(I);
							InputtedMove.Y *= -1;
							Input->PrimaryInputtedMove = InputtedMove;
						}
						else if (Input->Actions[I].Time > 0.0f)
						{
							i2 InputtedMove = CEuler(I);
							InputtedMove.Y *= -1;
							Input->SecondaryInputtedMove = InputtedMove;
						}
					}
				}

				i2 Temp = Input->PrimaryInputtedMove;
				Input->PrimaryInputtedMove = Input->SecondaryInputtedMove;
				Input->SecondaryInputtedMove = Temp;
			}
			else if (JustPressed.Num == 2 && Held.Num == 0)
			{
				s32 HaveChosenInput = false;
				for (s32 I = 0;
					I < CTAUINT;
					I += 2)
				{
					if (Input->Actions[I].JustPressed)
					{
						if (!HaveChosenInput)
						{
							i2 InputtedMove = CEuler(I);
							InputtedMove.Y *= -1;
							Input->PrimaryInputtedMove = InputtedMove;
							HaveChosenInput = true;
						}
						else
						{
							i2 InputtedMove = CEuler(I);
							InputtedMove.Y *= -1;
							Input->SecondaryInputtedMove = InputtedMove;
						}
					}
				}
			}
			else if (JustPressed.Num == 0 && Held.Num == 3)
			{
				Input->PrimaryInputtedMove = Held.Move;
				Input->SecondaryInputtedMove = i2{ 0,0 };
			}
			else if (JustPressed.Num == 3 && Held.Num == 0)
			{
				Input->PrimaryInputtedMove = JustPressed.Move;
				Input->SecondaryInputtedMove = i2{ 0,0 };
			}
		}

		b32 UndoHappened = false;
		if (GameState->UndoStack.NumEntries > 0)
		{
			if (Input->Actions[UNDO].JustPressed)
			{
				GameState->UndoStack.UndoCount = 1;
				UndoTurn(GameState, GameState->Level.Mutables, GameState->Level.NumMutables, &GameState->UndoStack);
			}
			else if (Input->Actions[UNDO].Pressed)
			{
				r32 UndoTime = GetUndoWaitTime(GameState->UndoStack.UndoCount);
				if (Input->Actions[UNDO].Time >= UndoTime)
				{
					++GameState->UndoStack.UndoCount;
					Input->Actions[UNDO].Time -= UndoTime;
					UndoTurn(GameState, GameState->Level.Mutables, GameState->Level.NumMutables, &GameState->UndoStack);
				}
			}
			else
			{
				GameState->UndoStack.UndoCount = 0;
			}
		}
		else
		{
			GameState->UndoStack.UndoCount = 0;
		}

		GameState->AgainTime += Input->dt;
		r32 WaitTime = GetEventWaitTime(GameState->RecentEvent);

		if (GameState->AgainTime >= WaitTime && GameState->UndoStack.UndoCount == 0)
		{
			if (GameState->RecentEvent == MOVED_LATERALLY || GameState->RecentEvent == SINGLE_STEP_FALL)
			{
				PerformMove(GameState, GameState->Level.Mutables, GameState->Level.NumMutables, GameState->RecentEvent);
			}
			GameState->RecentEvent = ExecuteTurn(GameState, GameState->Level.Immutables, GameState->Level.LevelSize, GameState->Level.Mutables, GameState->Level.NumMutables, Input->PrimaryInputtedMove, Input->SecondaryInputtedMove);
			if (WaitTime > 0.0f)
			{
				GameState->AgainTime -= WaitTime;
			}
			else
			{
				GameState->AgainTime = Input->dt;
			}
		}

		TweenAllObjects(GameState->Tweens, Input->dt);

		/*
		if (Input->Actions[UP].Pressed)
		{
			GameState->CameraPos.Y -= 1.0f;
		}
		if (Input->Actions[DOWN].Pressed)
		{
			GameState->CameraPos.Y += 1.0f;
		}
		if (Input->Actions[LEFT].Pressed)
		{
			GameState->CameraPos.X -= 1.0f;
		}
		if (Input->Actions[RIGHT].Pressed)
		{
			GameState->CameraPos.X += 1.0f;
		}
		

		ALLEGRO_TRANSFORM Transform;

		al_build_transform(&Transform, GameState->CameraPos.X, GameState->CameraPos.Y, 1.0f, 1.0f, 0.0f);
		al_use_transform(&Transform);
		*/

		UpdateCamera(GameState);

		Render(Window, GameState);
	}

}

s32
InitializeGame(FILE* Log,game_state* GameState)
{
	GameState->Screen = R2(v2{ 0.0f,0.0f }, HadamardDiv(GameState->Window.Rect.Size, v2{ GRID_PIXEL_LENGTH,GRID_PIXEL_LENGTH }));;
	GameState->AgainTime = 0.0f;
	Seed(&GameState->PRNG, 100);
	GameState->InEditor = false;


	fprintf(Log, "\nLoading Textures...");


	const char* ArtAsset[NUM_TEXTURES] = { "art\\sokovaniablocks5.png" };


	for (s32 I = 0;
		I < NUM_TEXTURES;
		++I)
	{
		GameState->TextureGroup[I].Bitmap = al_load_bitmap(ArtAsset[I]);
		if (GameState->TextureGroup[I].Bitmap == NULL)
		{
			fprintf(Log, "Failed: Couldn't open texture %s",ArtAsset[I]);
			return -1;
		}
	}

	s32 SubTextures = 1;
	for (s32 Y = 0;
		Y < 2;
		++Y)
	{
		for (s32 X = 0;
			X < 3;
			++X)
		{
			GameState->TextureGroup[SubTextures].Bitmap = GameState->TextureGroup[ATLAS_ID].Bitmap;
			GameState->TextureGroup[SubTextures].Angle = 0.0f;
			GameState->TextureGroup[SubTextures].Center = v2{ 0.0f,0.0f };
			GameState->TextureGroup[SubTextures].Region = r2{ ((r32)X * 34.0f+1.0f),((r32)Y*34.0f+1.0f),32.0f,32.0f };
			GameState->TextureGroup[SubTextures].Rect = r2{ v2{0.0f,0.0f},HadamardDiv(GameState->TextureGroup[SubTextures].Region.Size,v2{GRID_PIXEL_LENGTH,GRID_PIXEL_LENGTH})+ V2(2.0f / GRID_PIXEL_LENGTH,2.0F / GRID_PIXEL_LENGTH) };
			GameState->TextureGroup[SubTextures].Flags = 0;
			GameState->TextureGroup[SubTextures].Offset = -V2(1.0f / GRID_PIXEL_LENGTH, 1.0F / GRID_PIXEL_LENGTH);
			GameState->TextureGroup[SubTextures++].Tint = al_map_rgb(255, 255, 255);
		}
	}

	//GameState->TextureGroup[GRID_A_ID].Tint = al_map_rgba_f(1.0f, 1.0, 1.0, 0.5f);
	//GameState->TextureGroup[GRID_B_ID].Tint = al_map_rgba_f(0.4f, 0.4, 0.4, 1.0f);
	//GameState->TextureGroup[CHEBYSHEV_BLOCK_ID].Rect.Size = GameState->TextureGroup[CHEBYSHEV_BLOCK_ID].Rect.Size;
	//GameState->TextureGroup[CHEBYSHEV_BLOCK_ID].Offset = -V2(1.0f / GRID_PIXEL_LENGTH, 1.0F / GRID_PIXEL_LENGTH);

	//GameState->TextureGroup[CHEBYSHEV_WALL_ID].Region.Size = GameState->TextureGroup[CHEBYSHEV_WALL_ID].Region.Size - V2(1, 1);
	//GameState->TextureGroup[CHEBYSHEV_WALL_ID].Region.P = GameState->TextureGroup[CHEBYSHEV_WALL_ID].Region.P + V2(1, 1);
	//GameState->TextureGroup[METRICLESS_WALL_ID].Tint = al_map_rgba_f(0.0f, 0.0, 0.0, 1.0f);
	//GameState->TextureGroup[METRICLESS_BLOCK_ID].Rect.Size = GameState->TextureGroup[METRICLESS_BLOCK_ID].Rect.Size + V2(2.0f / GRID_PIXEL_LENGTH, 2.0F / GRID_PIXEL_LENGTH);
	//GameState->TextureGroup[METRICLESS_BLOCK_ID].Offset = -V2(1.0f / GRID_PIXEL_LENGTH, 1.0F / GRID_PIXEL_LENGTH);
	


#ifdef EDITOR_RUNNING
	for (s32 I = 0;
		I < 8;
		++I)
	{
		EditorTextures[I] = GameState->TextureGroup[I];
	}


	GameState->EditorTileMap = EditorInit(GameState->EditorTileMap, i2{100,100}, 10, 
		I2(GRID_PIXEL_LENGTH, GRID_PIXEL_LENGTH), 255, B2(GameState->Window.Rect));

#endif




	fprintf(Log, "Successful\n");

	GameState->AgainTime = 0.0f;
	GameState->UndoStack.UndoCount = 0;
	//GameState->PreviousMove = i2{ 1,0 };


	//TODO(ian): add freeze frame when blocks change type in midair!!!!!


	//Number of puzzles in demo: ~8
	//number of puzzles not in demo: ~18
	//Progress: ~26/40 = 65%
	
	//TODO(ian): should blocks be able to push the player? 
	//TODO(ian): there are alot of metricless floor levels; design some other types of levels
	//TODO(iaN):design levels where the player is going up instead of falling down


	//TODO(ian): Ideas for puzzles:
	//1) rescue a block in a pit
	//2) have an arch with three block height and two rows of blocks where you have the structure gain another row of height to traverse a gap
	//3) a regular puzzle and then the same puzzle upside down both with different solutions (maybe already solved)
	//4) have a puzzle that has an arch that is only 3 wide where the player can't move side to side, ie introduce them to the rule that blocks can't push the player
	//5) entrap the player inside a 4x4 square of blocks(????)

	/*
	//NOTE(ian): puzzles grouped by category
	TUTORIAL: sequence of 8
	STARTING: sequence of 5
	FALLING: sequence of 9
	METRICLESS: sequence of 6
	FLYING: sequence of 1?
	*/

	//NOTE(ian): ~25 puzzles total; trying to get up to 30 (or if I can 40)
	//TODO(ian): make sure all levels are top quality!!!!

	//TODO(ian): certain concepts aren't explored to their limits:
	//such as, how the player can transmogrify a group of blocks by moving them against a metricless wall

	//NOTE(ian): Beginning levels ~10 levels

	/*
	const char* Level =
	"ssssssssssssssss"
	"s......sx......s"
	"s......sx......s"
	"s......sx......s"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s......sxB.....s"
	"s......sx......s"
	"s......sx......s"
	"s......sx......s"
	"s......sx......s"
	"s......sx..BP..s"
	"s......sxxxxxxxs"
	"ssssssssssssssss";

	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s........xx....s"
	"s.......xs.....s"
	"s......xx......s"
	"s.....xx......xs"
	"s....xx......xxs"
	"s...xx....B.xx.s"
	"s..xx......xx..s"
	"s.xx....B.xx...s"
	"sxx......xx....s"
	"sx....B.xx.....s"
	"s......xx......s"
	"s....Pxx.......s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";



	KEEP!!!!!
	//NOTE(ian): need to see if there is another way to solve it
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s........xx....s"
	"s.......ss.....s"
	"s......ss......s"
	"s.....xx......xs"
	"s....xx......xxs"
	"s...xx....B.xx.s"
	"s..xx......xx..s"
	"s.xx....B.xx...s"
	"sxx......xx....s"
	"sx....B.xx.....s"
	"s......xx......s"
	"s....Pxx.......s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";



	KEEP!!!!
	/*
	const char* Level =
	"ssssssssssssssss"
	"ssssssssssssssss"
	"s..............s"
	"sPB.B..........s"
	"sxxxxx.........s"
	"s....s.........s"
	"s....s.........s"
	"s....sssssssxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..........xxxxs"
	"ssssssssssssssss";


	KEEEP!!!!!
	const char* Level =
	"ssssssssssssssss"
	"ssssssssssssssss"
	"s..............s"
	"sPB.B..........s"
	"sxxxxx.........s"
	"s....s.........s"
	"s....s.........s"
	"s....s..ssssxxxs"
	"s....ssss......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..........xxxxs"
	"ssssssssssssssss";


	KEEP!!!!
	const char* Level =
	"ssssssssssssssss"
	"ssssssssssssssss"
	"s..............s"
	"s.B............s"
	"s.x............s"
	"s..............s"
	"s.P............s"
	"sxxxxssssssssxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..........xxxxs"
	"ssssssssssssssss";

	*/


	/*
	//NOTE(ian): much better
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s.....xx.......s"
	"s.....x........s"
	"s.....s......xxs"
	"s.....s........s"
	"s.....s........s"
	"s.....x........s"
	"s.....xx.......s"
	"s....BxB.......s"
	"s.....xxx......s"
	"s....Bx........s"
	"sP......x......s"
	"sxxxxxxxx......s"
	"ssssssssssssssss";


	KEEP!!!!
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..B.B.........s"
	"sxxxxxx..s.....s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s......xxx.....s"
	"s......xxx.....s"
	"s......xxx.....s"
	"sxxxxxxxxxxxxxxs"
	"sP.............s"
	"sxxxxxxxx......s"
	"ssssssssssssssss";


	*/
	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s........x.....s"
	"s........s.....s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s...x.....x....s"
	"s..Bx..x..xB...s"
	"s..............s"
	"s............P.s"
	"sxxxxxxBxxxxxxxs"
	"ssssssssssssssss";

	

	*/
	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"sx.............s"
	"sxs............s"
	"sx.............s"
	"sx.............s"
	"sx..B..B...P...s"
	"sx..xxxxxxxxxxxs"
	"sxxxxxxxx......s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	*/
	/*
	KEEP!!!!!
	//NOTE(ian): this is pretty good. Keep/iterate upon this concept!!!
	const char* Level =
	"ssssssssssssssss"
	"s,,,,,,,,......s"
	"s..............s"
	"s..............s"
	"sP....B.B......s"
	"sxxxxxxxx......s"
	"sxxxxxbbb......s"
	"sxxxxxbxx......s"
	"sxxxxxxx.......s"
	"sxxxxxx........s"
	"sxxxxx.........s"
	"sxxxx..........s"
	"sxxx...........s"
	"sxx............s"
	"sx.........xxxxs"
	"ssssssssssssssss";

	const char* Level =
	"ssssssssssssssss"
	"s,,,,,,,,......s"
	"s..............s"
	"s......B.......s"
	"sP....B........s"
	"sxxxxxxxx......s"
	"sxxxxxxxx......s"
	"sxxxxxxxx......s"
	"sxxxxxxx.......s"
	"sxxxxxx........s"
	"sxxxxx.........s"
	"sxxxx..........s"
	"sxxx...........s"
	"sxx............s"
	"sx.........xxxxs"
	"ssssssssssssssss";

	KEEP!!!!!
	const char* Level =
	"ssssssssssssssss"
	"s,,,,,,,,......s"
	"s..............s"
	"s..............s"
	"sxsssxxxxxxxxxxs"
	"s........xssssss"
	"s........x..s..s"
	"s..............s"
	"sP...B........xs"
	"sx..B.B..xxs.sss"
	"sx...B...xssssss"
	"sxxxxxxxxx.....s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";



	const char* Level =
	"ssssssssssssssss"
	"s,,,,,,,,......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s....sxxxxxxxxxs"
	"s....s........xs"
	"s....s.........s"
	"ssssss.........s"
	"s..........B...s"
	"sxs.ssss..B..BPs"
	"sxxssssssssxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	
	
	//NOTE(ian): does this level have anything interesting to say?
	//might also be too similar to other levels
	const char* Level =
	//metricless floor 
	"ssssssssssssssss"
	"ssssssssssssssss"
	"s..............s"
	"s........B.B.BPs"
	"s.........xxxxxs"
	"s.........sxxxxs"
	"sD.D.D.D..sxxxxs"
	"ss.s.s.s.......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ss.s...........s"
	"ss.s...........s"
	"ss.s...........s"
	"ss.s...........s"
	"ssssssssssssssss";


	KEEP!!!
	const char* Level =
	"ssssssssssssssss"
	"sxxxxxxsssssss.s"
	"s..s..x...x..s.s"
	"s..s..x...x..s.s"
	"s..s..x...x..s.s"
	"s..s.........s.s"
	"s..s.........s.s"
	"s..s.........s.s"
	"s..x.........x.s"
	"s..s.........s.s"
	"s..s.........s.s"
	"s..s.........s.s"
	"s..xbbbbbbbbbx.s"
	"s..xxxxx.xxxxx.s"
	"s..x...x...p.x.s"
	"ssssxxxxxxxxxxss";


	//TODO(ian): should the flying levels be the end?
	//if so how many levels and how hard should they be?

	KEEP!!!!
	const char* Level =
	"ssssssssssssssss"
	"s.........xxxxxs"
	"s..............s"
	"sx.............s"
	"sssssssssss....s"
	"s.........xxxxs"
	"s...........B..s"
	"s..........B...s"
	"s...........BP.s"
	"s.........xxxxxs"
	"sssssssssss....s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	const char* Level =
	"ssssssssssssssss"
	"sx.............s"
	"sx........B.P..s"
	"s.......xxxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"sx.............s"
	"sx....B........s"
	"sx....D....xxxxs"
	"sx..DDDDD..sssss"
	"sx..ssssss.sssss"
	"sx.sssssss.sssss"
	"ss.sssssssssssss"
	"ssssssssssssssss"
	"ssssssssssssssss";


	
	//NOTE(ian): this is pretty good. Maybe try to find better way of expressing it?
	//Also make sure this is not trivially solved
	const char* Level =
	//metricless floor 
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s...........ssss"
	"s..B.B......xxxs"
	"s..B.B......x..s"
	"sxxxxx......x.xs"
	"s..ss.......x.xs"
	"s..ss.........xs"
	"s..ss.........ss"
	"s..ss.........ss"
	"s..ss.........ss"
	"s..sssDDDDDDDDss"
	"ssssssssssssssss"
	"ssssssssssssssss"
	"ssssssssssssssss";
	

	KEEP!!!!
	//NOTE(ian): this is really nice. Make sure there isn't a trivial way to solve it.
	//NOTE(ian): if this puzzle leadss to a dead end then the level could be simplified 
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s...xxxxxxxxsDss"
	"s.......s...sDss"
	"s.......s...sDss"
	"s.......s...sDss"
	"s.B.B.B.s.B.sDss"
	"sxxxxx..s..xsDss"
	"s....x.....xssss"
	"s....x.....x..ss"
	"s....x.....x..ss"
	"s....sssssssssss"
	"s.............ss"
	"ssssssssssssssss";


	//NOTE(ian): these are twin levels that are different versions of two other levels
	//they satisfy the conditions for the inverse level thing but is there another way to do this?


	const char* Level =
	"ssssssssssssssss"
	"s.ss..ss.....xss"
	"s.ss..ss.....xss"
	"s.ss..ss.....xss"
	"s.xx..xx.....xxs"
	"s..B...B.......s"
	"s..B...........s"
	"s..............s"
	"s..............s"
	"s...........B..s"
	"s........B..B..s"
	"sxx......xx.xx.s"
	"ssx......ss.ss.s"
	"ssx......ss.ss.s"
	"ssx......ss.ss.s"
	"ssssssssssssssss";

	KEEP!!!!
	"ssssssssssssssss"
	"ss......s......s"
	"s.......s......s"
	"s.......s......s"
	"s..xxxxxxxxxx.xs"
	"s..s........x..s"
	"s..s........x..s"
	"x..s........x..s"
	"s..s........x..s"
	"s..s........xP.s"
	"s..s........x..s"
	"s..xxxxxxxxxx..s"
	"s....B.B.B.....s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";



	
	//TODO(ian): if the blocks can push the player this puzzle is ruined
	const char* Level =
	"ssssssssssssssss"
	"s.............ss"
	"s.............ss"
	"s.............ss"
	"s.............ss"
	"s..B.B.B..B.B.ss"
	"sxxxxxxxx..B..ss"
	"ssssssBss.....ss"
	"s......Bs.....ss"
	"s......sB.....ss"
	"s.............ss"
	"s.............ss"
	"s.............ss"
	"s.............ss"
	"sxxxsDDDDDDDDDDs"
	"ssssssssssssssss";

	//NOTE(ian): is this a better version of the puzzle above? yes
	//also this might be too similar to the other puzzle about carrying blocks you went through
	const char* Level =
	//metricless floor
	"ssssssssssssssss"
	"s.............ss"
	"s..B.B.B......ss"
	"sxxxxxxxx.....ss"
	"sssssssss.....ss"
	"s.............ss"
	"s.............ss"
	"s.............ss"
	"s.....DDDDDDDDss"
	"s.....Dssssssss"
	"s.....D........s"
	"s.....D........s"
	"s.....D........s"
	"sDDDDDDDDDDD.xxs"
	"ssssssssssssssss"
	"ssssssssssssssss";




	//NOTE(ian): this is a good flying level; the player needs to make a specific shape:
	//maybe think of a better way to tell the player they need that?
	//TODO(ian): this level can be transfered to not flying. Should i do that?
	const char* Level =
	"sssssssssssssssssssssssssssssss"
	"s...........D.................s"
	"s...........D...........xxxxsss"
	"s...........D............BxBsss"
	"s...........D............BBxsss"
	"s...........D............BxBsss"
	"sB.B.B.B....D.................s"
	"sxxxxxx.....D.................s"
	"s.....s.....D.....s...........s"
	"s.....s.....D.....s...........s"
	"s.....s.....D.....s...........s"
	"s.....s.....D.....sxBBBBxxxxxxs"
	"s.....s.....D.....sxxxxxxxxxxxs"
	"s.....s.....D.....s...........s"
	"s.....s.....D.....s...........s"
	"sssssssssssssssssssssssssssssss";


	//NOTE(ian): when the player enters the puzzle there needs to be a blockade so they cannot take a three tall
	//structure out and then back in
	//NOTE(ian): this is very similar (visually) to a puzzle above; does removeing blocks help?
	//metricless floor
	"sssssssssssssssssssssssssssssss"
	"s.......................xxxxsss"
	"s.sssssssssssssssssssssssBxBsss"
	"s.ss.....................BBxsss"
	"s.ss.....................ssssss"
	"s.ss.....................sxxxxs"
	"s.ss............D.............s"
	"s.ss..xx........D.............s"
	"s.ss.Bxs........D.............s"
	"ssss..xsDDDDDDDDDDDDDDD.......s"
	"s....Bxssssssssssssssss.......s"
	"s.....x.....D.....sssss.......s"
	"s.....x.....D.....s...sssssssss"
	"s..B..x.....D.....s...........s"
	"sxxxxxx.......................s"
	"sssssssssssssssssssssssssssssss";



	//NOTE(ian): another goodish flying level; make sure this is the best way to present this puzzle
	//NOTE(ian): idea for flying levels: make the rooms gignatic so it is incredibly obvious that you need to fly
	const char* Level =
	"sssssssssssssssssssssssssssssss"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"sB.B.B.B.B....................s"
	"sxxxxxxxxx....................s"
	"ssssssssss...................xs"
	"ssssssssss...................xs"
	"ssssssssss...................xs"
	"sssssssssssssssssss..........xs"
	"sx...........................xs"
	"sx...........................xs"
	"sx............................s"
	"sx............................s"
	"sx............................s"
	"sssssssssssssssssssssssssssssss";



	//NOTE(ian)L this is a decent level; is there any way to simplify it?
	//the ideas is the you go over a pit but catch yourself with the block vehicle you made
	//NOTE(ian): workshop this; the idea is that you hook into a crevice and "pull yourself" up
	const char* Level =
	//this level is broken because the player can fly
	//metricless floor
	"sssssssssssssssssssssssssssssss"
	"s..............xBB............s"
	"s..............Bx.............s"
	"s..............Bs.............s"
	"s.P.B.B.BB.....Bs.............s"
	"sxxxxxxxxx.....Bs.............s"
	"s........s.....ssssss........xs"
	"s........s..........sssssssssxs"
	"s........s...................xs"
	"sx.......s...................xs"
	"sx.......s.DDDDD..D..........xs"
	"sx.......ssssssD..DDDDD.x....xs"
	"sx............ssssssssssx.....s"
	"sx............................s"
	"sx............................s"
	"sssssssssssssssssssssssssssssss";


	KEEP!!!
	//metricless floor
	"sssssssssssssssssssssssssssssss"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"sssssssssssssssssssssssssssx..s"
	"s........................xxx..s"
	"s.............................s"
	"sP............................s"
	"sx.xBxBxBxBxxxxs..............s"
	"sx.........x...sDDDDDDDDDDDDDDs"
	"sxxxxxxxxxxx...ssssssssssssssss"
	"s.............................s"
	"s.............................s"
	"sssssssssssssssssssssssssssssss";

	KEEP!!!!!
	//metricless floor
	"sssssssssssssssssssssssssssssss"
	"s.............sssssssssssssssss"
	"s........B....................s"
	"s.....BBB.....................s"
	"sxxxxxxxx.....................s"
	"s.......s.....................s"
	"s.......s.....................s"
	"s.......s.....................s"
	"s.......sDDDDDD.DDDDD...DDD...s"
	"s.......sssssss.sssssssssDs...s"
	"s.............s.DDDDsssssDs...s"
	"s.............xssssDDDDDDDs...s"
	"s.................sssssssss...s"
	"s.............................s"
	"s.............................s"
	"sssssssssssssssssssssssssssssss";
	
	//NOTE(ian):this level seems like it could be beaten by accident; try to fix that
	"sssssssssssssssssssssssssssssss"
	"s......x......................s"
	"s.......x.....................s"
	"s.B......x....................s"
	"sx........xxxxxxxxxsssss......s"
	"sxx.B..................s......s"
	"sxxx...................sxssssss"
	"sxxxx.B.......................s"
	"sxxxxx........................s"
	"sxxxxxxxxxxxsssssxxxxxxxs.s.sxs"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"sssssssssssssssssssssssssssssss";



	"sssssssssssssssssssssssssssssss"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"sssssssssssssssssssssssssssssss";


	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	//NOTE(ian): BIG WORLD LEVELS:


	"sssssssssssssssssssssssssssssss"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.s.s.s.s.s.s.s.s.sxs.s.s.s.s.s"
	"s.............................s"
	"s.....BBBB....................s"
	"s.....BBBB....................s"
	"ss....B..B....................s"
	"ssxxxxx.xxxxxx.s.s.s.s.sxs.s.xs"
	"s.....x......x................s"
	"s.....xxxxxx.x................s"
	"s..........x.x................s"
	"s..........x.x................s"
	"sssssssssssssssssssssssssssssss";


	//TODO(ian): so for now I decided to have a giant world but have the puzzles be discrete objects
	//you can restart them and so forth however any use of the blocks outside of the puzzles must
	//not have situations where the player can be in an unwinnable scenario


	//NOTE(ian): this is an adaptation of a blocks level; iterate, simplify
	//TODO(ian): question:the huge big world puzzles are massive; is this even worth it?
	//even the idea of the big world is very gimmicky and seems to distract from the rest of the game
	//and if I make the decision to have blocks push the player there is a serious danger the player will discover it before they are supposed to
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
	"sxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxBssssssssssssssssssssssssssss"
	"sx.................................sB..........................s"
	"sxBBBB.........................................................s"
	"sxB..B.........................................................s"
	"sxB.PB.........................................................s"
	"sxBBBB.........................................................s"
	"sx........................DDDD.................................s"
	"sx........................DDDD.................................s"
	"sx........................DDDD.................................s"
	"sx........................DDDD.................................s"
	"sxxxxxxxx...DDDDDDDDDDDDDDDDDDDDDDDDDDDD........xxxxxxxxxxxxxxxs"
	"s.......s...ssssssssssssssssssssssssssss........ssssssssssssssss"
	"s.......s...s..........................s........s..............s"
	"s.......s...s..........................s........s..............s"
	"s.......s...s..........................s........s..............s"
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";

	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"s..............................................................s"
	"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";

	"sssssssssssssssssssssssssssssss"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"sssssssssssssssssssssssssssssss";


	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";





	//NOTE(ian): BLOCK LEVELS
	//TODO(ian): make more block levels and convert them to trapped-in-chebyshev-box puzzles (4x4 box?)



	//TODO(ian): this accident is really fruitful. there is a lot of things to do with it. However, don't
	//do anything now as that distracts

	//NOTE(ian): this is a reprise of one of the tutorial levels; also reprise almost the entire tutorial level 
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"sx.............s"
	"sx.............s"
	"s..s...........s"
	"s..s...........s"
	"s..s...........s"
	"s..s...........s"
	"sx.............s"
	"sxB............s"
	"sx.............s"
	"sx....B........s"
	"sxxxxxxxxxxxxxxs"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"sx.............s"
	"sx.............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.B............s"
	"sx.............s"
	"sxx............s"
	"sxxx...........s"
	"sxxxxB.........s"
	"sxxxxxxxxxxxxxxs"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s........x.....s"
	"s........x.....s"
	"s........s.....s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s...x.....x....s"
	"s..Bx..x..x....s"
	"s..............s"
	"s............P.s"
	"sxxxxxxBxxxxxxxs"
	"ssssssssssssssss";


	const char* Level =
	"ssssssssssssssss"
	"sxB............s"
	"s..............s"
	"sB.B...........s"
	"sxx............s"
	"s.s............s"
	"s.s............s"
	"s.s............s"
	"s.sDDDD..DDDDDDs"
	"sssssss..sssssss"
	"s.....s..s.....s"
	"s.....s..s.....s"
	"s.....ssss.....s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	const char* Level =
	"ssssssssssssssss"
	"ssssssss.......s"
	"sxB....s.......s"
	"s......s.......s"
	"s..B...s.......s"
	"sxxxx..s.......s"
	"s...s..s.......s"
	"s...s..s.......s"
	"s...s..s.......s"
	"s...s..........s"
	"s...s..sxxxxxxxs"
	"s...ssxsssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	//NOTE(ian): not a puzzle but an interesting consequence to the rules; maybe a joke?
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.....xxx......s"
	"s.....x.x......s"
	"s.....x..B.....s"
	"s.....x.xxxxxxxs"
	"s.....x.x......s"
	"s.....xBx......s"
	"sB......x......s"
	"sxxxxxxBx......s"
	"sssssssss......s"
	"s..............s"
	"ssssssssssssssss";


	//TODO(ian): convert this to trapped-in-chebyshev-box puzzle
	//TODO(ian): this is too complicated; need to simplify; the basic idea is that you make a block chebyshev while others revert back
	"sssssssssssssssssssssssssssssss"
	"sxxxxxxxxxxxxxxxxxxxs.........s"
	"sx..................sss.......s"
	"sx....................sss.....s"
	"sx......................sss...s"
	"sx........................sss.s"
	"sx..........................sss"
	"sx............................s"
	"s........D....................s"
	"sxxx.DDDDDD.DDDD..............s"
	"sssssssssssssssDDD............s"
	"s.............ssDDD...........s"
	"s..............sssDDD.........s"
	"s................sssDDD.xxxxxxs"
	"s..................ssssssssssss"
	"sssssssssssssssssssssssssssssss";


	"sssssssssssssssssssssssssssssss"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"s.............................s"
	"sssssssssssssssssssssssssssssss";

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";
	
	
	
	//NOTE(ian): Diagonal Levels ~12 levels


	/*
	const char* Level =
	"ssssssssssssssss"
	"s.........sss..s"
	"sxxxxxxx......xs"
	"sxxxxxx..xB....s"
	"sssssx....ss...s"
	"s..............s"
	"s....xssssssssss"
	"s.B.xxxxxxxxxxxs"
	"sP.xxxxxxxxxxxxs"
	"sxxxxxxxxxxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	*/

	/*
	//NOTE(ian): this is a good reprise :)
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"sP..B.B...s....s"
	"sxxxxxxxs......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..........xxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";





	*/	


	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"sPB.B..........s"
	"sxxxxx......xxxs"
	"s....s......s..s"
	"s....s......s..s"
	"s....ssssssss..s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..........xxxxs"
	"ssssssssssssssss";







	/*
	const char* Level =
	"ssssssssssssssss"
	"s.........x....s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"sx.x.x.x.x.x.x.s"
	"s..............s"
	"s.x.x.x.x.x.x.xs"
	"s..............s"
	"sx.x.x.x.x.x.x.s"
	"s......B.......s"
	"s.xBx.xBx.xbx.xs"
	"s..P...........s"
	"ssssssssssssssss";

	/*
	//NOTE(ian): keep/iterate
	const char* Level =
	"ssssssssssssssss"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s......s.......s"
	"s....sss.......s"
	"s..............s"
	"sxx....x..BxxxBs"
	"sss....x.......s"
	"sss....x......Ps"
	"sssssssxxxxxxxxs"
	"ssssssssssssssss";

	*/
	/*
	//NOTE(ian): keep/iterate - this is pretty cool

	const char* Level =
	"ssssssssssssssss"
	"s.xxxxxxxxxxxxxs"
	"ss.ssxxxxxxxxxxs"
	"s.s.....xxxxxxxs"
	"s..x........xxxs"
	"sxxss..........s"
	"sxxxss.........s"
	"sxxxxsx........s"
	"sxxxxxss.......s"
	"sxxxxxxss......s"
	"s.......xx.....s"
	"sB..........x..s"
	"s.B........xxx.s"
	"s..B....P.xxxxxs"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";

	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s...........xxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.xxxxx........s"
	"s.x............s"
	"s.xB...Bxs.....s"
	"s.x.B.B.xs.....s"
	"s.x.....xs.....s"
	"sxx.....xs.....s"
	"sP......xs.....s"
	"sxxxxxxxxsssssss"
	"ssssssssssssssss";
	*/
	/*
	//NOTE(ian): keep/iterate - this concept should be taught
	const char* Level =
	"ssssssssssssssss"
	"s.........x....s"
	"s.........x....s"
	"s.........x....s"
	"s..............s"
	"s..............s"
	"s......x.......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.........xxx..s"
	"s.......B......s"
	"s..P...B.......s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";


	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"sxxxxxsxxxxxxxxs"
	"s.....x........s"
	"s....xx........s"
	"s....xx........s"
	"s.......B......s"
	"sP...x..BBB.xx.s"
	"sxxxxxxxx.xxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	*/
	/*
	//NOTE(ian): this is great :)

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..ss.ssss.....s"
	"sssss..........s"
	"s..ss..........s"
	"s..ss...xxx....s"
	"s.....xxx..xx..s"
	"s.....xx....xx.s"
	"s.....x..xx..xxs"
	"s...B...xxxx..ss"
	"sxxx..xxxssss..s"
	"s..xB.x..s..s..s"
	"sP....x..s..s..s"
	"sxxxxxx.....s..s"
	"ssssssssssssssss";

	/*


	//NOTE(ian): this one is really good :)
	const char* Level =
	"ssssssssssssssss"
	"s...sxs....s...s"
	"s...s....sxs...s"
	"s...sxs....s...s"
	"s...s....sxs...s"
	"s...sxs....s...s"
	"s...s....sxs...s"
	"s...sxs....s...s"
	"s...s....sxs...s"
	"s...sxs....s...s"
	"s...s....sxs...s"
	"s...s.BBB..s...s"
	"s...s.x....s...s"
	"s...s..P...s...s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";



	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s.B.B..........s"
	"sPB.B.B........s"
	"sxxxxx.........s"
	"ssss...........s"
	"s..............s"
	"sx.............s"
	"s.............xs"
	"s..............s"
	"s...........DDDs"
	"sDB........DDDDs"
	"sDD.......DDDDDs"
	"sDDDDDDDDDDDDDDs"
	"ssssssssssssssss";

	*/
	/*
	//NOTE(ian): much better?
	const char* Level =
	"ssssssssssssssss"
	"s..x...........s"
	"s..x...........s"
	"s..xxx.........s"
	"s..xs..........s"
	"s..xs..........s"
	"s..xs..........s"
	"s..xs..........s"
	"s..xs.....s....s"
	"s..xs....x.....s"
	"s..xs...x......s"
	"s..xxxxx.......s"
	"s.P.B.B.B......s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	/*
	//NOTE(ian): this is pretty good I think; test it to see whether people like it
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.........D....s"
	"s.........D....s"
	"s.........D....s"
	"s.........D....s"
	"s.........D.P..s"
	"sBssssDsDsDsBxxs"
	"sxsssss.s.s.sBBs"
	"ssssssssssssssss";

	/*
	//NOTE(ian): beginning of metricless block exploration
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.B............s"
	"sxxxxx.........s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sP.............s"
	"sxxssssssssssxxs"
	"ssssssssssssssss";

	/*
	//NOTE(ian): is this actually good?
	const char* Level =
	"ssssssssssssssss"
	"s......x.......s"
	"s......x.......s"
	"s......x.......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s....x.........s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.....s........s"
	"s.......B.B.B..s"
	"sP......x.x.x..s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";


	*/

	//NOTE(ian): Special Block Levels: ~9
	//TODO(ian): Should I keep these puzzles?
	//Pros: explores certain facets of the movement mechanics
	//Cons: doesn't integrate well with other mechanics and general progression

	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss"
	"sxx............s"
	"ssss.sxxxxx....s"
	"ssss.sx...x....s"
	"ssss.sx.x.x....s"
	"s.......x..BP..s"
	"sxssssBxxxxxxxxs"
	"sxssssxxxxxxxxxs"
	"s..............s"
	"ssssssssssssssss";

	*/
	/*

	


	/*
	const char* Level =
	"ssssssssssssssss"
	"sx.............s"
	"sx........B.P..s"
	"s.......xxxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"sx.............s"
	"sx....B........s"
	"sx....D....xxxxs"
	"sx..DDDDD..sssss"
	"sx..ssssss.sssss"
	"sx.sssssss.sssss"
	"ss.sssssssssssss"
	"ssssssssssssssss"
	"ssssssssssssssss";

	*/

	/*
	//NOTE(ian): maybe?
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss"
	"ss.............s"
	"ss.............s"
	"ss..B..........s"
	"s.PB...........s"
	"sxxxxs....sxxxxs"
	"s...xs.D..ssssss"
	"s...xsssssssssss"
	"s...xs....ssssss"
	"s...xsssssssssss"
	"ssssssssssssssss";


	/*
	//NOTE(ian): there are two solutions to this; iterate?
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s.....Bxs....xxs"
	"s.....Bxs....sss"
	"s......xs....sss"
	"s......xs....sss"
	"s.....Pxssssssss"
	"ssssssssssssssss";
	*/
	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s...xxx........s"
	"s...xs.........s"
	"s...ss.........s"
	"s...ss.........s"
	"s...sssB......Ps"
	"s...ssx...xxxxxs"
	"s...xssssssssxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	*/
	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.......s......s"
	"s.P.....x......s"
	"s.x.xBx.x.x.x.xs"
	"sxxxxxxxxxxxxxxx"
	"ssssssssssssssss";


	/*



	//TODO(ian): try to transfer this one to non-special block!!!
	//NOTE(ian): pretty good
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s...........x..s"
	"s..............s"
	"s..............s"
	"s......s.......s"
	"s......xxxxxxsss"
	"s......x.......s"
	"s..P...x.......s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";

	*/
	/*
	//TODO(ian): try to transfer this one to non-special block
	const char* Level =
	"ssssssssssssssss"
	"s.....sxxxxxxxxs"
	"s..............s"
	"s..........P...s"
	"s.....ssxxxxxxxs"
	"s.....ssxxxxxxxs"
	"s.....ssxxxxxxxs"
	"sxxxxxssxxxxxxxs"
	"s...........xxxs"
	"s...........xxxs"
	"s..............s"
	"s..............s"
	"sxxxx..........s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.......B..P...s"
	"s.......xxxxxxxs"
	"s.....s.xxxxxxxs"
	"s.........xxxxxs"
	"s.........xxxxxs"
	"s...........xxxs"
	"s...........xxxs"
	"s..............s"
	"sxxxx..........s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	//NOTE(ian): Flying levels ~6


	/*
	const char* Level =
	"ssssssssssssssss"
	"s.........xxxxxs"
	"s..............s"
	"sx.............s"
	"s..............s"
	"s..............s"
	"s...........B..s"
	"s..........B...s"
	"s...........BP.s"
	"s.......ssxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	*/


	/*
	const char* Level =
	"ssssssssssssssss"
	"sx.............s"
	"sx.............s"
	"s........sxxxxxs"
	"s..............s"
	"ssssssssssssssss"
	"s..sss......B..s"
	"sx.........B...s"
	"sx..........BP.s"
	"sx.........xxxxs"
	"sx.........sssss"
	"sx.......s.sssss"
	"sx.s.s.s.s.sssss"
	"ss.s.s.sssssssss"
	"ssssssssssssssss"
	"ssssssssssssssss";

	/*
	const char* Level =
	"ssssssssssssssss"
	"sxbb......xxxxxs"
	"sbxb...........s"
	"sb.b......xxxx.s"
	"sb..........Bx.s"
	"sx...........P.s"
	"sx..........Bx.s"
	"sx........xxxxxs"
	"sx........ssssss"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sxxxx.......xxxs"
	"s..............s"
	"ssssssssssssssss";



	//NOTE(ian): if blocks can't push blocks of different types
	//then this puzzle is broken
	/*
	//NOTE(ian): this is a neat idea and it's much better! :)
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s.......B......s"
	"s......B.......s"
	"s.......B...P..s"
	"s......xxxxxxxxs"
	"s......s.......s"
	"s......sss.....s"
	"s........s.....s"
	"s........sss...s"
	"s..........s...s"
	"sss........sss.s"
	"s.s..........s.s"
	"s.sss........sss"
	"ssssssssssssssss";


	*/
	/*
	//NOTE(ian): this is really good! Keep/iterate

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s...B..........s"
	"s..B......BB...s"
	"s..B.B.....BB..s"
	"s...B.B....B...s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";



	/*
	//NOTE(ian): Much better :)
	const char* Level =
	"ssssssssssssssss"
	"s..........s...s"
	"s..........s...s"
	"s..........s...s"
	"s..........s...s"
	"s..........s...s"
	"sss........sssss"
	"s.s............s"
	"s.s............s"
	"s.s............s"
	"s.ssss.........s"
	"s....s.....B...s"
	"s....s....B....s"
	"s....s....PBBsss"
	"s....ssxxxxxxxxs"
	"ssssssssssssssss";
	*/
	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s...........B..s"
	"s..........B...s"
	"s........B..B.Ps"
	"s........xxxxxxs"
	"s........s.....s"
	"s......sss.....s"
	"s......s.......s"
	"s....sss.......s"
	"s....s.........s"
	"s..sss.........s"
	"ssssssssssssssss";


	//NOTE(ian): Garbage/Misc

	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s.xxxxxssBssxxxs"
	"s.x.....Bsssssss"
	"s.xxxxsss..BB..s"
	"s..BBB...sssxx.s"
	"s.xxxxsss....x.s"
	"s.x..........x.s"
	"s.x..........x.s"
	"s.xxxxxxxxxxxx.s"
	"s..............s"
	"s.......x......s"
	"s.......x......s"
	"sP......x......s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";

	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s...........xxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.xxsss........s"
	"s.x............s"
	"s.xb...bxs.....s"
	"s.x.b.b.xs.....s"
	"s.x.....xs.....s"
	"sxx.....xs.....s"
	"sp......xs.....s"
	"sxxxxxxxxsssssss"
	"ssssssssssssssss";

	/*

	const char* Level =
	"ssssssssssssssss"
	"s.............xs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s......x.......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.....xxb......s"
	"s..............s"
	"s..x...........s"
	"s.xbx..bxbx.p..s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";




	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.....x.x.x....s"
	"s.....x..bx....s"
	"s.....xxxxx....s"
	"s.....x...x....s"
	"s.....xxx.x....s"
	"s..............s"
	"s.........x....s"
	"s.............ps"
	"sxxxxxxxxbxxxxxs"
	"ssssssssssssssss";









	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s......bb...b..s"
	"s.......x....b.s"
	"s.....bb..bbx..s"
	"s............b.s"
	"s.............bs"
	"s...........p..s"
	"sxsss......sxxxs"
	"s...ssssssss...s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";



	/*

	//TODO(ian): this level can be beaten by moving diagonally; can players discover this on their own or is it too obfuscated?
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.x..b.........s"
	"s.xxxxx........s"
	"s.xx.......xxxxs"
	"s.x............s"
	"s.x............s"
	"s.p.b..........s"
	"sxxxxxx........s"
	"s..............s"
	"ssssssssssssssss";



	/*
	//elevator
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.......B......s"
	"s.......B......s"
	"s.......B......s"
	"sxxxxxxxBxxxxxxs"
	"s......B.......s"
	"s.....B........s"
	"s....B.........s"
	"s.....B........s"
	"s......B.......s"
	"ssssssssssssssss";


	//OR gate
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.......sxxxxxxs"
	"s........B.....s"
	"s.......sxxxxxxs"
	"s........B.....s"
	"s.......sxxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.....s....P...s"
	"sxxxxxBBxxxxxxxs"
	"ssssssssssssssss";


	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s.B.B..B....P..s"
	"sxxxxxxxxxx.xxxs"
	"s.........s.s..s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.......sxxxxxxs"
	"s.......s......s"
	"s.....sss......s"
	"s.....s........s"
	"s...sss........s"
	"s...s..........s"
	"ssssssssssssssss";


	*/




	//TODO(ian):change the file format for levels
	
	fprintf(Log, "Loading \'world_map.txt\'...");
	ALLEGRO_FILE* F = al_fopen("levels\\world_map.txt", "r");
	if (F == NULL)
	{ 
		fprintf(Log, "Failed: Couldn't open file.");
		return -1;
	}
	int64_t FSize = al_fsize(F);




	//TODO(ian): after testing mechanics, change this!!!!!
	//GameState->Level.Immutables = (s8*)AllocateChunk(FSize + 1);
	//assert(GameState->Level.Immutables);
	al_fread(F, (void*)GameState->Level.Immutables, FSize);
	GameState->Level.Immutables[FSize] = 0;
	al_fclose(F);

	GameState->Level.LevelSize = i2{ 0,0 };
	for (s32 I = 0;
		I < (s32)FSize;
		++I)
	{
		s8 Field = GameState->Level.Immutables[I];
		if (Field == '\n')
		{
			if (GameState->Level.LevelSize.X == 0)
			{
				GameState->Level.LevelSize.X = I + 1;
			}
			else
			{
				if (((I % GameState->Level.LevelSize.X) + 1) != GameState->Level.LevelSize.X)
				{
					fprintf(Log, "Failed: world is not rectangular");
					return -1;
				}
			}
			++GameState->Level.LevelSize.Y;
		}
	}

	//printf("\nLength of Level = %d", strlen((char*)GameState->Level));

	if ((FSize) != (GameState->Level.LevelSize.X + 1) * GameState->Level.LevelSize.Y)
	{
		fprintf(Log, "Failed: \'world_map.txt\' is not formatted correctly");
		return -1;
	}


	fprintf(Log, "Successful\n");

	/*
	s32 HalfNumRows = (GameState->Level.LevelSize.Y / 2);
	for (s32 Y = 0;
		Y < HalfNumRows;
		++Y)
	{
		for (s32 X = 0;
			X < GameState->Level.LevelSize.X;
			++X)
		{
			s32 TopIndex = Y * GameState->Level.LevelSize.X + X;
			s32 BottomIndex = (GameState->Level.LevelSize.Y - Y - 1)*GameState->Level.LevelSize.X + X;
			s8 Temp = GameState->Level.Immutables[TopIndex];
			GameState->Level.Immutables[TopIndex] = GameState->Level.Immutables[BottomIndex];
			GameState->Level.Immutables[BottomIndex] = Temp;
		}
	}
	*/

	GameState->Level.NumMutables = 0;
	for (s32 I = 0;
		I < (s32)FSize;
		++I)
	{
		s8 Field = GameState->Level.Immutables[I];
		if (IsCracked(Field))
		{

			s32 Index = GameState->Level.NumMutables;
			if (IsChebyshevCrate(Field))
			{
				GameState->Level.Mutables[Index].Flags = SetBits(GameState->Level.Mutables[Index].Flags, CHEBYSHEV_FLAG);
			}
			else if (IsMetriclessCrate(Field))
			{
				GameState->Level.Mutables[Index].Flags = SetBits(GameState->Level.Mutables[Index].Flags, METRICLESS_FLAG);
			}
			else if (IsPlayer(Field))
			{
				Index = 0;
				GameState->Level.Mutables[GameState->Level.NumMutables] = GameState->Level.Mutables[0];
				GameState->Level.Mutables[Index].Flags = 0;
				GameState->Level.Mutables[Index].Flags = SetBits(GameState->Level.Mutables[Index].Flags, PLAYER_FLAG);
			}

			//NOTE(ian): this assumes that LevelSize.X is known which assumes the top row of the world has no movers!
			GameState->Level.Mutables[Index].Pos = I2((u32)I, GameState->Level.LevelSize.X);
			GameState->Level.Mutables[Index].Rect = R2(V2(GameState->Level.Mutables[Index].Pos), v2{ 1.0f,1.0f });

			GameState->Level.Immutables[I] = InitializeEmpty();

			++GameState->Level.NumMutables;
		}
	}


	GameState->Screen.P = (GameState->Level.Mutables[0].Rect.P + GameState->Level.Mutables[0].Rect.Size*0.5f - GameState->Screen.Size*0.5f);


	return 0;
}

int
main(int argc, char **argv)
{
	
	
	FILE* Log;
	s32 Error = (s32)fopen_s(&Log, "log.txt", "w");

	if (Error != 0)
	{
		printf("Opening \'log.txt\' was unsuccesful.\nPress 0 then ENTER to quit.");
		scanf_s("%d", &Error);
		return -1;
	}
	
	game_state GameState = {};

	i2 WindowSize = i2{ 960, 540 };


	GameState.Window.Rect = r2{ 0.0f,0.0f,(r32)WindowSize.X,(r32)WindowSize.Y };

	fprintf(Log, "Initializing...");

	if (!al_init())
	{
		fprintf(Log, "Failed to initialize allegro!");
		return -1;
	}

	ALLEGRO_DISPLAY *Display = NULL;

	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_REQUIRE);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_REQUIRE);
	//al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 16, ALLEGRO_REQUIRE);
	//al_set_new_display_option(ALLEGRO_COLOR_SIZE, 32, ALLEGRO_REQUIRE);
	//al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 16, ALLEGRO_REQUIRE);
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_new_window_title("Sokovania");

	Display = al_create_display(WindowSize.X, WindowSize.Y);
	if (!Display)
	{
		fprintf(Log, "Failed to create display!");
		return -1;
	}

	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

	ALLEGRO_TIMER *Timer = al_create_timer(1.0f);
	if (!Timer)
	{
		fprintf(Log, "Failed to create timer!");
		return -1;
	}

	ALLEGRO_TIMER *FrameRate = al_create_timer(1.0f / FPS);
	if (!FrameRate)
	{
		fprintf(Log, "Failed to create framerate timer!");
		return -1;
	}

	ALLEGRO_EVENT_QUEUE *EventQueue = al_create_event_queue();
	if (!EventQueue)
	{
		fprintf(Log, "Failed to create event queue!");
		return -1;
	}

	if (!al_install_keyboard())
	{
		fprintf(Log, "Failed to initialize the keyboard!");
		return -1;
	}

	if (!al_init_image_addon())
	{
		fprintf(Log, "Failed to initialize allegro image addon!");
		return -1;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(Log, "Failed to initialize allegro primitives addon!");
		return -1;
	}

	if (!al_install_mouse())
	{
		fprintf(Log, "Failed to initialize the mouse!");
		return -1;
	}



	fprintf(Log, "Successful");

	ALLEGRO_KEYBOARD_STATE KeyboardState;

	al_register_event_source(EventQueue, al_get_display_event_source(Display));
	al_register_event_source(EventQueue, al_get_timer_event_source(Timer));
	al_register_event_source(EventQueue, al_get_timer_event_source(FrameRate));
	al_register_event_source(EventQueue, al_get_keyboard_event_source());
	al_register_event_source(EventQueue, al_get_mouse_event_source());

	al_set_target_bitmap(al_get_backbuffer(Display));

	user_input Input = {};

	Input.dt = 1.0f / FPS;

	Input.Actions[UP].KeyOne = ALLEGRO_KEY_UP;
	Input.Actions[UP].KeyTwo = ALLEGRO_KEY_W;

	Input.Actions[DOWN].KeyOne = ALLEGRO_KEY_DOWN;
	Input.Actions[DOWN].KeyTwo = ALLEGRO_KEY_S;


	Input.Actions[LEFT].KeyOne = ALLEGRO_KEY_LEFT;
	Input.Actions[LEFT].KeyTwo = ALLEGRO_KEY_A;


	Input.Actions[RIGHT].KeyOne = ALLEGRO_KEY_RIGHT;
	Input.Actions[RIGHT].KeyTwo = ALLEGRO_KEY_D;


	Input.Actions[UNDO].KeyOne = ALLEGRO_KEY_Z;
	Input.Actions[UNDO].KeyTwo = ALLEGRO_KEY_U;

	Input.Actions[RESTART].KeyOne = ALLEGRO_KEY_R;
	Input.Actions[RESTART].KeyTwo = ALLEGRO_KEY_R;

	Input.Actions[SELECT].KeyOne = ALLEGRO_KEY_ENTER;
	Input.Actions[SELECT].KeyTwo = ALLEGRO_KEY_SPACE;

	Input.Actions[BACK].KeyOne = ALLEGRO_KEY_ESCAPE;
	Input.Actions[BACK].KeyTwo = ALLEGRO_KEY_BACKSPACE;

	Input.Actions[EDITOR_RUN].KeyOne = ALLEGRO_KEY_F6;
	Input.Actions[EDITOR_RUN].KeyTwo = ALLEGRO_KEY_F6;

	Input.Actions[EDITOR_TOOL_SELECT].KeyOne = ALLEGRO_KEY_S;
	Input.Actions[EDITOR_TOOL_SELECT].KeyTwo = ALLEGRO_KEY_S;

	Input.Actions[EDITOR_TOOL_BRUSH].KeyOne = ALLEGRO_KEY_B;
	Input.Actions[EDITOR_TOOL_BRUSH].KeyTwo = ALLEGRO_KEY_B;

	Input.Actions[EDITOR_TOOL_ERASE].KeyOne = ALLEGRO_KEY_E;
	Input.Actions[EDITOR_TOOL_ERASE].KeyTwo = ALLEGRO_KEY_E;

	Input.Actions[EDITOR_TOOL_RECTANGLE].KeyOne = ALLEGRO_KEY_Q;
	Input.Actions[EDITOR_TOOL_RECTANGLE].KeyTwo = ALLEGRO_KEY_Q;

	Input.Actions[EDITOR_TOOL_EYEDROPPER].KeyOne = ALLEGRO_KEY_D;
	Input.Actions[EDITOR_TOOL_EYEDROPPER].KeyTwo = ALLEGRO_KEY_D;
	
	Input.Actions[EDITOR_TOOL_LINK].KeyOne = ALLEGRO_KEY_L;
	Input.Actions[EDITOR_TOOL_LINK].KeyTwo = ALLEGRO_KEY_L;

	Input.Actions[EDITOR_ACT_TOGGLE_GRID].KeyOne = ALLEGRO_KEY_G;
	Input.Actions[EDITOR_ACT_TOGGLE_GRID].KeyTwo = ALLEGRO_KEY_G;

	Input.Actions[EDITOR_ACT_TOGGLE_LINKS].KeyOne = ALLEGRO_KEY_K;
	Input.Actions[EDITOR_ACT_TOGGLE_LINKS].KeyTwo = ALLEGRO_KEY_K;

	Input.Actions[EDITOR_ACT_UNDO].KeyOne = ALLEGRO_KEY_Z;
	Input.Actions[EDITOR_ACT_UNDO].KeyTwo = ALLEGRO_KEY_U;

	Input.Actions[EDITOR_ACT_REDO].KeyOne = ALLEGRO_KEY_R;
	Input.Actions[EDITOR_ACT_REDO].KeyTwo = ALLEGRO_KEY_R;

	Input.Actions[EDITOR_ACT_UNDO].KeyOne = ALLEGRO_KEY_Z;
	Input.Actions[EDITOR_ACT_UNDO].KeyTwo = ALLEGRO_KEY_U;

	Input.Actions[EDITOR_ACT_CUT].KeyOne = ALLEGRO_KEY_X;
	Input.Actions[EDITOR_ACT_CUT].KeyTwo = ALLEGRO_KEY_X;

	Input.Actions[EDITOR_ACT_COPY].KeyOne = ALLEGRO_KEY_C;
	Input.Actions[EDITOR_ACT_COPY].KeyTwo = ALLEGRO_KEY_C;

	Input.Actions[EDITOR_ACT_PASTE].KeyOne = ALLEGRO_KEY_V;
	Input.Actions[EDITOR_ACT_PASTE].KeyTwo = ALLEGRO_KEY_V;

	Input.Actions[EDITOR_SCROLL_LEFT].KeyOne = ALLEGRO_KEY_LEFT;
	Input.Actions[EDITOR_SCROLL_LEFT].KeyTwo = ALLEGRO_KEY_LEFT;

	Input.Actions[EDITOR_SCROLL_RIGHT].KeyOne = ALLEGRO_KEY_RIGHT;
	Input.Actions[EDITOR_SCROLL_RIGHT].KeyTwo = ALLEGRO_KEY_RIGHT;

	Input.Actions[EDITOR_SCROLL_UP].KeyOne = ALLEGRO_KEY_UP;
	Input.Actions[EDITOR_SCROLL_UP].KeyTwo = ALLEGRO_KEY_UP;

	Input.Actions[EDITOR_SCROLL_DOWN].KeyOne = ALLEGRO_KEY_DOWN;
	Input.Actions[EDITOR_SCROLL_DOWN].KeyTwo = ALLEGRO_KEY_DOWN;




	al_start_timer(Timer);
	al_start_timer(FrameRate);

	if (InitializeGame(Log, &GameState))
	{
		return -1;
	}




	s32 FramesPerSec = 0;
	while (1)
	{
		ALLEGRO_EVENT Ev;
		al_wait_for_event(EventQueue, &Ev);
		if (Ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		else if (Ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			for (s32 I = 0;
				I < NUM_KEY_ACTIONS;
				I++)
			{
				if (Ev.keyboard.keycode == Input.Actions[I].KeyOne || Ev.keyboard.keycode == Input.Actions[I].KeyTwo)
				{
					//++Input.Actions[I].NumPresses;
					Input.Actions[I].Pressed = true;
					Input.Actions[I].JustPressed = true;
					Input.Actions[I].Time = 0.0f;
					//break;
				}
			}
		}
		else if (Ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			for (s32 I = 0;
				I < NUM_KEY_ACTIONS;
				I++)
			{
				if (Ev.keyboard.keycode == Input.Actions[I].KeyOne || Ev.keyboard.keycode == Input.Actions[I].KeyTwo)
				{
					Input.Actions[I].Pressed = false;
					Input.Actions[I].Time = 0.0f;
					Input.Actions[I].JustReleased = true;
					//break;
				}
			}

			
		}
		else if (Ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (Ev.mouse.button == 1)//NOTE(ian): assuming this is left
			{
				Input.Actions[EDITOR_LEFT_CLICK].Pressed = false;
				Input.Actions[EDITOR_LEFT_CLICK].Time = 0.0f;
				Input.Actions[EDITOR_LEFT_CLICK].JustReleased = true;
			}
			else
			{
				Input.Actions[EDITOR_RIGHT_CLICK].Pressed = false;
				Input.Actions[EDITOR_RIGHT_CLICK].Time = 0.0f;
				Input.Actions[EDITOR_RIGHT_CLICK].JustReleased = true;
			}

			Input.MousePos.X = Ev.mouse.x;
			Input.MousePos.Y = Ev.mouse.y;
		}
		else if (Ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (Ev.mouse.button == 1)//NOTE(ian): assuming this is left
			{
				Input.Actions[EDITOR_LEFT_CLICK].Pressed = true;
				Input.Actions[EDITOR_LEFT_CLICK].Time = 0.0f;
				Input.Actions[EDITOR_LEFT_CLICK].JustPressed = true;
			}
			else
			{
				Input.Actions[EDITOR_RIGHT_CLICK].Pressed = true;
				Input.Actions[EDITOR_RIGHT_CLICK].Time = 0.0f;
				Input.Actions[EDITOR_RIGHT_CLICK].JustPressed = true;
			}
			Input.ChangeInMousePos.X = Ev.mouse.x - Input.MousePos.X;
			Input.ChangeInMousePos.Y = Ev.mouse.y - Input.MousePos.Y;
			Input.MousePos.X = Ev.mouse.x;
			Input.MousePos.Y = Ev.mouse.y;
		}
		else if (Ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			Input.MouseWheel = Ev.mouse.dz;
			Input.ChangeInMousePos.X = Ev.mouse.dx;
			Input.ChangeInMousePos.Y = Ev.mouse.dy;
			Input.MousePos.X = Ev.mouse.x;
			Input.MousePos.Y = Ev.mouse.y;
		}
		else if (Ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (Ev.timer.source == FrameRate)
			{
				b32 AnyInput = false;
				for (s32 I = 0;
					I < NUM_KEY_ACTIONS;
					++I)
				{
					if (!Input.Actions[I].JustPressed && !Input.Actions[I].JustReleased)
					{
						Input.Actions[I].Time += 1.0f / FPS;
					}
					if (Input.Actions[I].Pressed)
					{
						AnyInput = true;
					}
				}


				if (AnyInput == Input.ReceivedInput)
				{
					Input.TimeSinceInputChange += 1.0f / FPS;
				}
				else
				{
					Input.TimeSinceInputChange = 0.0f;
					Input.ReceivedInput = AnyInput;
				}
				



				GameUpdateAndRender(&GameState.Window, &GameState, &Input);


				for (s32 I = 0;
					I < NUM_KEY_ACTIONS;
					++I)
				{
					Input.Actions[I].JustPressed = Input.Actions[I].JustReleased = false;
				}

				++FramesPerSec;
			}
			else
			{

				//TODO(ian): have debug text drawn on screen
				printf("\nFPS: %d", FramesPerSec);
				//printf("\nMousePos = ( %d, %d )", Input.MousePos.X, Input.MousePos.Y);
				FramesPerSec = 0;
			}
		}
	}

	al_destroy_display(Display);

	al_destroy_timer(Timer);
	al_destroy_timer(FrameRate);

	return 0;
}
