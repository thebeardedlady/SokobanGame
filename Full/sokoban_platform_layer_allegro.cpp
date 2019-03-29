#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>



#define FPS 30.0f
#define local_persist static
#define global_variable static
#define internal static

#define ArrayCount(array) (sizeof(array)/sizeof((array)[0]))
#define Max(a,b) a > b ? a : b
#define Min(a,b) a < b ? a : b

#define DEBUG 1

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
		Result = Angle % 8;
	}
	else
	{
		Result = 8 - ((-Angle) % 8);
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

union v2 {
	struct {
		r32 X;
		r32 Y;
	};
	r32 E[2];
};


inline i2
I2(v2 A)
{
	i2 Result;
	Result.X = (s32)A.X;
	Result.Y = (s32)A.Y;
	return Result;
}

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







union v3 {
	struct {
		union {
			struct {
				r32 X;
				r32 Y;
				r32 Z;
			};
			struct {
				v2 XY;
				r32 Z;
			};
		};
	};
	struct {
		r32 R;
		r32 G;
		r32 B;
	};
};


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

inline v3
Normalized(v3 A)
{
	r32 Size = Length(A);
	Assert(Size != 0.0f);
	v3 Result = A / Size;
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

inline s32
RandomRange(prng_state *State, s32 Min, s32 Max)
{
	s32 Result = Min + (s32)(NextRandom(State) % (u64)((Max + 1) - Min));
	return Result;
}

inline r32
RandomUnilateral(prng_state *State)
{
	r32 Result = (r32)NextRandom(State) / (r32)((u64)0xffffffffffffffff);
	return Result;
}

typedef struct {
	s32 X;
	s32 Y;
	s32 W;
	s32 H;
}render_dim;

typedef struct {
	s32 X;
	s32 Y;
}render_coord;

typedef struct {
	v2 P;
	r32 R;
}circle;

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

inline i2
Barycentric(b2 Box, i2 Point)
{
	i2 Result;
	Result.X = (Point.X - Box.X) / Box.W;
	Result.Y = (Point.Y - Box.Y) / Box.H;
	return Result;
}

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
	Result.P = Hadamard(Result.P, Result.Size);
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





typedef struct {
	union {
		struct {
			v3 P;
			v3 Size;
		};
		struct {
			r32 X;
			r32 Y;
			r32 Z;
			r32 W;
			r32 H;
			r32 L;
		};
	};
}r3;


inline r2
IgnoreZ(r3 Rect)
{
	r2 Result;
	Result.X = Rect.X;
	Result.Y = Rect.Y;
	Result.W = Rect.W;
	Result.H = Rect.H;

	return Result;
}

inline v2
GetLinePlaneIntersection(v3 P, v3 V, r32 H)
{
	r32 t = (H - P.Z) / V.Z;
	v2 Result;
	Result.X = P.X + t * V.X;
	Result.Y = P.Y + t * V.Y;
	return Result;
}

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


inline b32
AreBitsSet(u32 Field, u32 Mask)
{
	b32 Result = ((Field & Mask) == Mask);
	return Result;
}

inline b32
AreAnyBitsSet(u32 Field, u32 Mask)
{
	b32 Result = ((Field & Mask) != 0);
	return Result;
}

inline u32
SetBits(u32 Field, u32 Mask)
{
	u32 Result = Field | Mask;
	return Result;
}

inline u32
EraseBits(u32 Field, u32 Mask)
{
	u32 Result = (Field & ~Mask);
	return Result;
}



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




internal u32
OutCode(render_dim *Rect, s32 X, s32 Y)
{
	/*
	const int INSIDE = 0; // 0000
	const int LEFT = 1;   // 0001
	const int RIGHT = 2;  // 0010
	const int BOTTOM = 4; // 0100
	const int TOP = 8;    // 1000
	*/


	u32 Code = 0;

	if (X < Rect->X)
	{
		Code |= 1;
	}
	else if (X > Rect->X + Rect->W)
	{
		Code |= 2;
	}
	if (Y < Rect->Y)
	{
		Code |= 4;
	}
	else if (Y > Rect->Y + Rect->H)
	{
		Code |= 8;
	}

	return Code;
}

internal void
ClipLine(render_dim *Rect, s32 *X0, s32 *Y0, s32 *X1, s32 *Y1)
{
	u32 Outcode0 = OutCode(Rect, *X0, *Y0);
	u32 Outcode1 = OutCode(Rect, *X1, *Y1);
	b32 accept = 0;

	while (true) {
		if (!(Outcode0 | Outcode1))
		{
			accept = true;
			break;
		}
		else if (Outcode0 & Outcode1)
		{
			*X0 = 0;
			*Y0 = 0;
			*X1 = 0;
			*Y1 = 0;
			break;
		}
		else
		{
			s32 X, Y;
			u32 OutcodeOut = Outcode0 ? Outcode0 : Outcode1;

			if (OutcodeOut & 8)
			{
				X = *X0 + (*X1 - *X0) * ((Rect->Y + Rect->H) - *Y0) / (*Y1 - *Y0);
				Y = (Rect->Y + Rect->H);
			}
			else if (OutcodeOut & 4)
			{
				X = *X0 + (*X1 - *X0) * (Rect->Y - *Y0) / (*Y1 - *Y0);
				Y = Rect->Y;
			}
			else if (OutcodeOut & 2)
			{
				Y = *Y0 + (*Y1 - *Y0) * ((Rect->X + Rect->W) - *X0) / (*X1 - *X0);
				X = (Rect->X + Rect->W);
			}
			else if (OutcodeOut & 1)
			{
				Y = *Y0 + (*Y1 - *Y0) * (Rect->X - *X0) / (*X1 - *X0);
				X = Rect->X;
			}

			if (OutcodeOut == Outcode0) {
				*X0 = X;
				*Y0 = Y;
				Outcode0 = OutCode(Rect, *X0, *Y0);
			}
			else {
				*X1 = X;
				*Y1 = Y;
				Outcode1 = OutCode(Rect, *X1, *Y1);
			}
		}
	}
}


internal u32
OutCode(r2 *Rect, v2 A)
{
	/*
	const int INSIDE = 0; // 0000
	const int LEFT = 1;   // 0001
	const int RIGHT = 2;  // 0010
	const int BOTTOM = 4; // 0100
	const int TOP = 8;    // 1000
	*/


	u32 Code = 0;

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
	u32 Outcode0 = OutCode(Rect, *A);
	u32 Outcode1 = OutCode(Rect, *B);
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
			u32 OutcodeOut = Outcode0 ? Outcode0 : Outcode1;

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

internal void
RasterizeLine(u8 *Pixels, s32 Pitch, s32 X0, s32 Y0, s32 X1, s32 Y1,
	u8 R, u8 G, u8 B, u8 A)
{
	s32 dX = Abs(X1 - X0);
	s32 dY = -Abs(Y1 - Y0);
	s32 sX = X0<X1 ? 1 : -1;
	s32 sY = Y0<Y1 ? 1 : -1;
	s32 Error = dX + dY;
	s32 Error2; /* error value e_xy */
	s32 StartX = X0;
	s32 StartY = Y0;

	while (true)
	{
		//SetPixel(Pixels, Pitch, X0, Y0, R, G, B, A);
		if (X0 == X1 && Y0 == Y1) break;

		Error2 = 2 * Error;

		if (Error2 >= dY) /* e_xy+e_x > 0 */
		{
			Error += dY;
			X0 += sX;
		}

		if (Error2 <= dX) /* e_xy+e_y < 0 */
		{
			Error += dX;
			Y0 += sY;
		}
	}
}

/*
=================================
========MEMORY=MANAGEMENT========
=================================
*/

typedef struct {

};

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




typedef struct {
	ALLEGRO_BITMAP* Bitmap;
	ALLEGRO_COLOR Tint;
	r2 Region;
	r2 Rect;
	v2 Center;
	r32 Angle;
	s32 Flags;
}texture;

union render_object {
	//NOTE(ian): Textures
	typedef struct {
		s32 Type;
		ALLEGRO_BITMAP* Bitmap;
		ALLEGRO_COLOR Tint;
		ALLEGRO_SHADER* Shader;
		r2 Region;
		v2 Pos;
		v2 Scale;
		v2 Center;//TODO(ian): what exactly does this variable mean?
		r32 Angle;
	};
	//TODO(ian): add more types of objects to render!!!
};


void
DrawRect(texture Window, r2 Screen,texture Texture)
{
	r2 TextureRect = RelativeRectTransformation(Screen, Texture.Rect, Window.Rect);
	
	al_draw_tinted_scaled_rotated_bitmap_region(Texture.Bitmap, Texture.Region.X, Texture.Region.Y, Texture.Region.W, Texture.Region.H,
		Texture.Tint, Texture.Center.X, Texture.Center.Y, Floor(TextureRect.X), Floor(TextureRect.Y), TextureRect.W / Texture.Region.W, TextureRect.H / Texture.Region.H, Texture.Angle, Texture.Flags);
}




enum movement_direction {
	UP = 1,
	DOWN = 2,
	LEFT = 4,
	RIGHT = 8
};


#define MAX_BLOCKS 1000
typedef struct {
	r2 Rect;
	i2 Pos;
	i2 Move;
	s32 Type;
	s32 ID;//TODO(ian): Is this needed?
	s32 Flags;
} block;






typedef struct {
	i2 Move;
	s32* Data;
	s32 NumData;
} mover_data;


typedef struct {
	r32 TimeHeld;
	u32 KeyOne;
	u32 KeyTwo;
	s32 NumPresses;
	b32 Pressed;
}key_action;

typedef struct {
	key_action Undo;
	key_action Restart;
	key_action Up;
	key_action Down;
	key_action Left;
	key_action Right;
	key_action Action;
	r32 dt;
}user_input;

#define MAX_UNDO_WORDS 50000
typedef struct {
	s32 Words[MAX_UNDO_WORDS];
	s32 NumEntries;
	s32 NumWords;
} undo_stack;


enum gameplay_flags {
	ALL_DOWN = 0,
	DIAGONAL_MOVEMENT_ACTIVATED = 1,
	SPECIAL_BLOCK_ACTIVATED = 2
};

enum bitmap_type {
	EMPTY_TEXTURE,
	GRID_TEXTURE,
	PLAYER_NORMAL_TEXTURE,
	PLAYER_DIAGONAL_TEXTURE,
	PLAYER_SPECIAL_TEXTURE,
	CHEBYSHEV_WALL_TEXTURE,
	METRICLESS_WALL_TEXTURE,
	CHEBYSHEV_BLOCK_TEXTURE,
	METRICLESS_BLOCK_TEXTURE
};

typedef struct {
	texture Textures[50];
}texture_group;





typedef struct {
	undo_stack UndoStack;
	s8* Level;
	i2 LevelSize;
	r2 Screen;
	texture Window;
	texture_group TextureGroup;
	s32 NumBlocks;
	block Blocks[MAX_BLOCKS];
	prng_state PRNG;
	mover_data Movers;
	i2 PreviousMove;
	s32 PlayerIndex;
	s32 SpecialBlockIndex;
	s32 GameplayFlags;
	s32 RecentEvent;
	s32 UndoCount;
	r32 AgainTime;
	r64 tSine;
	u16 SoundOffset;
}game_state;

typedef struct {
	v2 Hit;
	r32 LinePer;
	r32 RayPer;
}ray_variables;



inline b32
SticksToWalls(s8 Entry)
{
	b32 Result = (Entry == 'b' || Entry == 'p');
	return Result;
}

inline b32
LinksToCrates(s8 Entry)
{
	b32 Result = (Entry == 'b' || Entry == 'p');
	return Result;
}

inline b32
IsImmediateFootingOnly(s8 Entry)
{
	b32 Result = (Entry == 'd' || Entry == 'p' || Entry == 'n');
	return Result;
}

inline b32
IsMoveable(s8 Entry)
{
	b32 Result = (Entry == 'p' || Entry == 'd' || Entry == 'b' || Entry == 'n' || Entry == 'm');
	return Result;
}


inline b32
IsCrate(s8 Entry)
{
	b32 Result = (Entry == 'd' || Entry == 'b' || Entry == 'n' || Entry == 'm');
	return Result;
}

inline b32
AcceptsInput(s8 Entry)
{
	b32 Result = (Entry == 'p');
	return Result;
}

inline b32
IsSpecialBlock(s8 Entry)
{
	b32 Result = (Entry == 'n' || Entry == 'm');
	return Result;
}

inline b32
IsMetriclessWall(s8 Entry)
{
	b32 Result = (Entry == 's');
	return Result;
}

inline b32
IsChebyshevWall(s8 Entry)
{
	b32 Result = (Entry == 'x');
	return Result;
}

inline b32
IsMetriclessCrate(s8 Entry)
{
	b32 Result = (Entry == 'd' || Entry == 'n');
	return Result;
}

inline b32
IsChebyshevCrate(s8 Entry)
{
	b32 Result = (Entry == 'b' || Entry == 'm');
	return Result;
}

inline b32
IsPlayer(s8 Entry)
{
	b32 Result = (Entry == 'p');
	return Result;
}

inline b32
IsEmpty(s8 Entry)
{
	b32 Result = (Entry == '.');
	return Result;
}


inline s8
InitializePlayer()
{
	return 'p';
}

inline s8
InitializeEmpty()
{
	return '.';
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

inline s8
InitializeSpecialBlock()
{
	return 'n';
}

inline ray_variables
Ray2D(v2 Ray, v2 RayPoint, v2 LinePoint, v2 LineRay)
{
	ray_variables Variables = ray_variables{ v2{ 0.0f, 0.0f }, -1.0f,-1.0f };
	r32 RaysCross = Cross(Ray, LineRay);
	if (RaysCross != 0.0f)
	{
		r32 t = Cross(LinePoint - RayPoint, LineRay) / RaysCross;
		r32 Epsilon = 0.005f;
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
PushOntoUndoStack(s8*Level, i2 LevelSize, i2  Move, s32* Indices, s32 NumIndices, undo_stack* UndoStack)
{

	s32 Diff = 0;
	Diff += (Move.X > 0 ? 1 : (Move.X < 0 ? -1 : 0));
	Diff += (Move.Y > 0 ? LevelSize.X : (Move.Y < 0 ? -LevelSize.X : 0));

	for (s32 I = 0;
		I < NumIndices;
		++I)
	{
		UndoStack->Words[UndoStack->NumWords++] = (s32)Level[Indices[I]];
		UndoStack->Words[UndoStack->NumWords++] = Indices[I] + Diff;
		UndoStack->Words[UndoStack->NumWords++] = -Diff;
	}

	UndoStack->Words[UndoStack->NumWords++] = NumIndices;
	++UndoStack->NumEntries;
}



//TODO(ian): fix bug where it tries to update with no data in undo stack
internal void
UpdateUndoStack(game_state* GameState, s8*Level, i2 LevelSize, i2 Move, s32* Indices, s32 NumIndices, undo_stack* UndoStack)
{
	s32 Diff = 0;
	Diff += (Move.X > 0 ? 1 : (Move.X < 0 ? -1 : 0));
	Diff += (Move.Y > 0 ? LevelSize.X : (Move.Y < 0 ? -LevelSize.X : 0));
	s32 NumLeftWords = UndoStack->NumWords - (3 * (UndoStack->Words[UndoStack->NumWords - 1]) + 1);
	s32 NumEntriesIndex = UndoStack->NumWords - 1;
	for (s32 I = 0;
		I < NumIndices;
		++I)
	{
		s32 UndoIndex = -1;
		for (s32 J = UndoStack->NumWords - 4;
			J >= NumLeftWords;
			J -= 3)
		{
			if (Indices[I] == UndoStack->Words[J + 1])
			{
				UndoIndex = J;
				break;
			}
		}
		if (UndoIndex != -1)
		{
			UndoStack->Words[UndoIndex + 1] += Diff;
			UndoStack->Words[UndoIndex + 2] -= Diff;
		}
		else
		{
			if (NumEntriesIndex + 4 < MAX_UNDO_WORDS)
			{
				UndoStack->Words[NumEntriesIndex + 3] = UndoStack->Words[NumEntriesIndex] + 1;
				UndoStack->Words[NumEntriesIndex] = (s32)Level[Indices[I]];
				UndoStack->Words[NumEntriesIndex + 1] = Indices[I] + Diff;
				UndoStack->Words[NumEntriesIndex + 2] = -Diff;
				UndoStack->NumWords += 3;
				NumEntriesIndex += 3;
			}
			else
			{
				printf("\nUndoStack Overflowed!!!");
				Assert(0);
			}
		}
	}

}

internal void
UndoTurn(game_state* GameState, s8 *Level, i2 LevelSize, undo_stack* UndoStack)
{
	s32 NumLeftWords = UndoStack->NumWords - (3 * (UndoStack->Words[UndoStack->NumWords - 1]) + 1);
	for (s32 I = UndoStack->NumWords - 4;
		I >= NumLeftWords;
		I -= 3)
	{
		s32 IndexToErase = UndoStack->Words[I + 1];
		Level[IndexToErase] = '.';
	}
	for (s32 I = UndoStack->NumWords - 4;
		I >= NumLeftWords;
		I -= 3)
	{
		s32 IndexToPlace = UndoStack->Words[I + 1] + UndoStack->Words[I + 2];
		Level[IndexToPlace] = (s8)UndoStack->Words[I];
		if (IsPlayer(UndoStack->Words[I]))
		{
			GameState->PlayerIndex = IndexToPlace;
		}
	}

	UndoStack->NumWords = NumLeftWords;
	--UndoStack->NumEntries;
}


internal void
RestartTurn(s8 *Grid, i2 LevelSize, s32* PreviousState, u32*TotalStateBytes, u32* TotalStateEntries)
{

}


#define MAXMOVEABLES 20

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
	for (u32 K = 0;
		K < NumIndices;
		++K)
	{
		if (Index == Indices[K])
		{
			Result = (s32)K;
			break;
		}
	}
	return Result;

}



internal b32
AlreadyTagged(i2* Indices, s32 NumIndices, i2 Index)
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

internal void
TagType(s8* Grid, i2 LevelSize, s32* Indices, s32* NumIndices, s32 X, s32 Y, s8 Type)
{
	for (s32 I = 0;
		I < 8;
		++I)
	{
		i2 Vector = CEuler(I);
		s32 Index = ((Y + Vector.Y)*LevelSize.Y + X + Vector.X);
		s8 SurroundingCell = Grid[Index];
		if (SurroundingCell == Type)
		{
			if (!AlreadyTagged(Indices, *NumIndices, Index))
			{
				Indices[(*NumIndices)++] = Index;
				TagType(Grid, LevelSize, Indices, NumIndices, X + Vector.X, Y + Vector.Y, Type);
			}
		}
	}
}



internal b32
IsSticky(s8* Grid, i2 LevelSize, s32* Indices, s32* NumIndices, s32 X, s32 Y)
{
	b32 Sticky = false;
	for (s32 I = -1;
		I < 2;
		++I)
	{
		for (s32 J = -1;
			J < 2;
			++J)
		{
			//TODO(ian): this is way to specific; is the rule universal or is it dependent on type?
			//TODO(ian): this causes an exception when player hits the edge of the level!!!
			s32 Index = (Y + I)*LevelSize.X + X + J;
			s8 SurroundingCell = Grid[Index];

			if (IsChebyshevWall(SurroundingCell))
			{
				Sticky = true;
				break;
			}
			else if (IsChebyshevCrate(SurroundingCell))
			{
				if (!AlreadyTagged(Indices, *NumIndices, Index))
				{
					Indices[(*NumIndices)++] = Index;
					if ((Sticky = IsSticky(Grid, LevelSize, Indices, NumIndices, X + J, Y + I)))
					{
						break;
					}
				}
			}

		}

		if (Sticky)
		{
			break;
		}
	}

	return Sticky;
}



internal void
ClearMoverFlags(game_state*GameState, block*Blocks, s32 NumBlocks)
{
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		Blocks[I].Flags = 0;
	}
}

enum phsyics_flags {
	EMPTY_FLAG = 0,
	CONNECTED_TO_CHEBYSHEV = 1,
	SURROUNDED_BY_METRICLESS = 2,
	SOMETHING_UNDERNEATH = 4
};

internal b32
AssignPhysicsFlagsType(game_state* GameState, s8*Level, i2 LevelSize,block* Blocks, s32 NumBlocks)
{
	for (s32 I = 0;
		I < NumBlocks;
		++I)
	{
		Blocks[I].Flags = 0;
	}

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
				if (IsChebyshevWall(Field))
				{
					Blocks[I].Flags = (s32)SetBits((u32)Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV);
				}
				else if (IsMetriclessWall(Field))
				{
					Blocks[I].Flags = (s32)SetBits((u32)Blocks[I].Flags, SURROUNDED_BY_METRICLESS);
				}
			}
		}

		if (!IsEmpty(Level[(Blocks[I].Pos.Y - 1)*LevelSize.X + Blocks[I].Pos.X]))
		{
			Blocks[I].Flags = (s32)SetBits((u32)Blocks[I].Flags, SOMETHING_UNDERNEATH);
		}
	}

	b32 PatternFound;
	do {
		PatternFound = false;
		for (s32 I = 0;
			I < NumBlocks;
			++I)
		{
			if (!AreBitsSet((u32)Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV))
			{
				b32 Break = false;
				for (s32 J = 0;
					J < NumBlocks;
					++J)
				{
					for (s32 K = -1;
						K < 2;
						++K)
					{
						for (s32 L = -1;
							L < 2;
							++L)
						{
							if (I2(Blocks[I].Pos.X + L, Blocks[I].Pos.Y + K) == Blocks[J].Pos)
							{
								Blocks[I].Flags = (s32)SetBits((u32)Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV);
								PatternFound = true;
								Break = true;
								break;
							}
						}
						if (Break)
						{
							break;
						}
					}
					if (Break)
					{
						break;
					}
				}
			}
		}


	} while (PatternFound);


	//NOTE(ian): Something Underneath
	do {
		PatternFound = false;
		for (s32 I = 0;
			I < NumBlocks;
			++I)
		{
			if (!AreBitsSet((u32)Blocks[I].Flags, SURROUNDED_BY_METRICLESS | CONNECTED_TO_CHEBYSHEV | SOMETHING_UNDERNEATH))
			{
				b32 Break = false;
				for (s32 J = 0;
					J < NumBlocks;
					++J)
				{

					for (s32 K = -1;
						K < 2;
						++K)
					{
						for (s32 L = -1;
							L < 2;
							++L)
						{
							if (I2(Blocks[I].Pos.X + L, Blocks[I].Pos.Y + K) == Blocks[J].Pos)
							{
								Blocks[I].Flags = (s32)SetBits((u32)Blocks[I].Flags, CONNECTED_TO_CHEBYSHEV);
								PatternFound = true;
								Break = true;
								break;
							}
						}
						if (Break)
						{
							break;
						}
					}
					if (Break)
					{
						break;
					}
				}
			}
		}


	} while (PatternFound);




	b32 ChangesHappening = false;
	for (s32 Y = 0;
		Y < GameState->LevelSize.Y;
		++Y)
	{
		for (s32 X = 0;
			X < GameState->LevelSize.X;
			++X)
		{
			s32 Index = Y * GameState->LevelSize.X + X;
			s8 SurroundingCell = Grid[Index];
			if (IsChebyshevCrate(SurroundingCell))
			{
				s32 Indices[100];
				s32 NumIndices = 0;
				if (!IsSticky(Grid, GameState->LevelSize, Indices, &NumIndices, X, Y))
				{
					b32 AroundMetriclessWall = false;
					for (s32 I = -1;
						I < 2;
						++I)
					{
						for (s32 J = -1;
							J < 2;
							++J)
						{
							if (IsMetriclessWall(Grid[(Y + I)*GameState->LevelSize.X + X + J]))
							{
								AroundMetriclessWall = true;
								break;
							}
						}

						if (AroundMetriclessWall)
						{
							break;
						}
					}

					if (AroundMetriclessWall)
					{
						Grid[Index] = 'd';
						ChangesHappening = true;
					}

				}
			}
			else if (IsMetriclessCrate(SurroundingCell))
			{
				if (AcceptsInput(SurroundingCell))
				{
					//Grid[Index].Properties = InitializePlayerProperties();
					//GameState->OtherSpecialAbilityActivated = false;
				}
				else
				{
					s32 Indices[100];
					s32 NumIndices = 0;
					if (IsSticky(Grid, GameState->LevelSize, Indices, &NumIndices, X, Y))
					{
						Grid[Index] = 'b';
						ChangesHappening = true;
					}
				}
			}
		}
	}
	return ChangesHappening;
}





internal b32
IsFalling(s8* Grid, i2 LevelSize, s32* Indices, s32* NumIndices, s32 X, s32 Y, s8 BlockStuff, u32 RecursionDepth = 0)
{
	b32 Falling = true;

	if (IsMoveable(BlockStuff))
	{
		s32 PrimaryIndex = (Y - 1)*LevelSize.X + X;
		s8 BlockUnderneath = Grid[PrimaryIndex];
		b32 IsType = BlockUnderneath == BlockStuff;
		if (BlockStuff == 'd')
		{
			IsType = (BlockUnderneath == '.');
		}
		if (!IsType && BlockUnderneath != '.')
		{
			if (RecursionDepth == 0 || !IsImmediateFootingOnly(BlockStuff)) return false;
		}
	}

	for (s32 I = -1;
		I < 2;
		++I)
	{
		for (s32 J = -1;
			J < 2;
			++J)
		{
			//TODO(ian): this is way to specific; is the rule universal or is it dependent on type?
			//TODO(ian): this causes an exception when player hits the edge of the level!!!
			s32 Index = ((Y + I)*LevelSize.X + X + J);
			s8 SurroundingCell = Grid[Index];
			if (!AlreadyTagged(Indices, *NumIndices, Index))
			{
				if (IsChebyshevWall(SurroundingCell))
				{
					return false;
				}
				else if (IsChebyshevCrate(SurroundingCell))
				{
					Indices[(*NumIndices)++] = Index;
					if (!IsFalling(Grid, LevelSize, Indices, NumIndices, X + J, Y + I, BlockStuff, RecursionDepth + 1))
					{
						return false;
					}
				}
			}
		}

		if (!Falling)
		{
			break;
		}
	}

	return Falling;
}





internal void
PushBlocksOnMoveStack(game_state* GameState, s32* Indices, s32* NumIndices, i2* Movers, i2 Move, s32 X, s32 Y)
{
	for (s32 I = -1;
		I < 2;
		++I)
	{
		for (s32 J = -1;
			J < 2;
			++J)
		{

			u32 Index = (u32)((Y + I)*GameState->LevelSize.X + X + J);
			if (IsChebyshevCrate(GameState->Level[Index]))
			{
				if (!AlreadyTagged(Indices, *NumIndices, Index))
				{
					Indices[(*NumIndices)] = Index;
					Movers[(*NumIndices)++] = Move;
					PushBlocksOnMoveStack(GameState, Indices, NumIndices, Movers, Move, X + J, Y + I);
				}
			}
		}
	}
}


internal void
ApplyMoveToBlocks(game_state* GameState, s32* Indices, i2* Movers, s32* NumIndices, i2 Move, s32 X, s32 Y)
{
	for (s32 I = -1;
		I < 2;
		++I)
	{
		for (s32 J = -1;
			J < 2;
			++J)
		{

			s32 Index = ((Y + I)*GameState->LevelSize.X + X + J);
			if (IsChebyshevCrate(GameState->Level[Index]))
			{
				s32 TagIndex = FindIndex(Indices, *NumIndices, Index);
				if (TagIndex != -1)
				{
					if (Movers[TagIndex] != Move)
					{
						Movers[TagIndex] = Move;
						ApplyMoveToBlocks(GameState, Indices, Movers, NumIndices, Move, X + J, Y + I);
					}
				}
			}
		}
	}
}


inline b32
MoveOrderLessThan(i2 LevelSize, s32 A, s32 B, s32 Angle)
{
	v2 Origin = v2{ (r32)(A % LevelSize.X),(r32)(A / LevelSize.X) };
	v2 Point = v2{ (r32)(B % LevelSize.X),(r32)(B / LevelSize.X) };
	v2 FloatValue = ComplexMult(Point - Origin, CEuler(8.0f - (r32)Angle));
	b32 Result = (FloatValue.X < 0.0f);
	return Result;
}


//NOTE(ian): Insertion sort
internal void
SortMovers(i2 LevelSize, s32 *Indices, s32 NumIndices, s32 Angle)
{
	s32 I = 1;
	while (I < NumIndices)
	{
		s32 J = I;
		while (J > 0 && MoveOrderLessThan(LevelSize, Indices[J], Indices[J - 1], Angle))
		{
			s32 temp = Indices[J];
			Indices[J] = Indices[J - 1];
			Indices[J - 1] = temp;
			J -= 1;
		}
		I += 1;
	}
}


internal void
CheckCrateRules(game_state* GameState, i2 Move, s32* Indices, i2* Movers, s32* NumIndices)
{
	b32 FoundPattern;
	do
	{
		FoundPattern = false;
		for (s32 I = 0;
			I < (s32)(*NumIndices);
			++I)
		{
			i2 NearPos = i2{ (Indices[I] % GameState->LevelSize.X),(Indices[I] / GameState->LevelSize.X) };
			NearPos = NearPos + Movers[I];
			s32 Index = NearPos.Y*GameState->LevelSize.X + NearPos.X;
			s8 Cell = GameState->Level[Index];
			if ((IsChebyshevCrate(Cell) || IsMetriclessCrate(Cell)) && !AlreadyTagged(Indices, *NumIndices, Index))
			{
				Indices[(*NumIndices)] = Index;
				Movers[(*NumIndices)++] = Move;
				if (IsChebyshevCrate(Cell))
				{
					PushBlocksOnMoveStack(GameState, Indices, NumIndices, Movers, Move, NearPos.X, NearPos.Y);
				}
				FoundPattern = true;
			}
		}
	} while (FoundPattern);


	do
	{
		FoundPattern = false;
		for (s32 I = 0;
			I < *NumIndices;
			++I)
		{
			if (TLength(Movers[I]) != 0 && !IsPlayer(GameState->Level[Indices[I]]))
			{
				i2 NearPos = i2{ (s32)(Indices[I] % GameState->LevelSize.X),(s32)(Indices[I] / GameState->LevelSize.X) };
				NearPos = NearPos + Movers[I];
				s32 Index = NearPos.Y*GameState->LevelSize.X + NearPos.X;
				s8 Cell = GameState->Level[Index];
				s32 IndicesIndex = FindIndex(Indices, *NumIndices, Index);
				b32 IsStopped = false;
				if (IndicesIndex == -1)
				{
					IsStopped = IsChebyshevWall(Cell) || IsMetriclessWall(Cell) || IsPlayer(Cell);


				}
				else
				{
					IsStopped = (IsChebyshevWall(Cell) || IsMetriclessWall(Cell) || IsPlayer(Cell))
						|| (IsChebyshevCrate(Cell) && LengthSq(Movers[IndicesIndex]) == 0)
						|| (IsMetriclessCrate(Cell) && LengthSq(Movers[IndicesIndex]) == 0);
				}


				if (IsStopped)
				{

					if (IsChebyshevCrate(GameState->Level[Indices[I]]))
					{
						ApplyMoveToBlocks(GameState, Indices, Movers, NumIndices, i2{ 0,0 }, NearPos.X - Movers[I].X, NearPos.Y - Movers[I].Y);
					}
					Movers[I] = i2{ 0,0 };
					FoundPattern = true;
				}
			}
		}
	} while (FoundPattern);


}





//TODO(ian): This is really ugly; clean this up!!!
internal u32
SetUpPlayerMove(game_state* GameState, i2 Move, s32* Indices, s32* NumIndices)
{
	i2 PlayerPos;
	i2 Movers[100];
	PlayerPos.X = GameState->PlayerIndex%GameState->LevelSize.X;
	PlayerPos.Y = GameState->PlayerIndex / GameState->LevelSize.X;
	*NumIndices = 1;
	Indices[0] = GameState->PlayerIndex;
	Movers[0] = Move;
	u32 AdjacentIndex = (PlayerPos.Y + Move.Y) * GameState->LevelSize.X + (Move.X + PlayerPos.X);


	if (IsChebyshevWall(GameState->Level[AdjacentIndex]) || IsMetriclessWall(GameState->Level[AdjacentIndex])) //#2 Player against Wall/spike
	{
		Movers[0] = i2{ 0,0 };
		*NumIndices = 0;
	}
	else if (IsPlayer(GameState->Level[AdjacentIndex]))
	{
		*NumIndices = 0;
	}
	else if (IsEmpty(GameState->Level[AdjacentIndex])) // #4 Player in empty square
	{
		if (!IsSticky(GameState->Level, GameState->LevelSize, Indices, NumIndices, PlayerPos.X + Move.X, PlayerPos.Y + Move.Y))
		{
			*NumIndices = 0;
			Movers[0] = i2{ 0,0 };
		}
		else
		{
			*NumIndices = 1;
		}
	}
	else if (IsMetriclessCrate(GameState->Level[AdjacentIndex]) || IsChebyshevCrate(GameState->Level[AdjacentIndex])) // #5  player pushes block
	{
		Indices[(*NumIndices)] = AdjacentIndex;
		Movers[(*NumIndices)++] = Move;

		if (IsChebyshevCrate(GameState->Level[AdjacentIndex]))
		{
			PushBlocksOnMoveStack(GameState, Indices, NumIndices, Movers, Move, PlayerPos.X + Move.X, PlayerPos.Y + Move.Y); // #6 Block 'pushes' blocks
		}

		CheckCrateRules(GameState, Move, Indices, Movers, NumIndices);

		// #9 Player against stationary block
		if (LengthSq(Movers[1]) == 0)
		{
			Movers[0] = i2{ 0,0 };
			*NumIndices = 0;
		}

	}
	return *NumIndices;
}


internal void
PerformMove(game_state* GameState, i2 Move, s32* Indices, s32 NumIndices)
{
	s32 Angle = GetAngle(Move);
	SortMovers(GameState->LevelSize, Indices, NumIndices, Angle);
	GameState->PreviousMove = Move;

	s32 OldPlayerIndex = 0;
	for (u32 I = 0;
		I < NumIndices;
		++I)
	{

		u32 NearbyIndex = (Move.Y + (Indices[I] / GameState->LevelSize.X))*GameState->LevelSize.X + Move.X + (Indices[I] % GameState->LevelSize.X);
		GameState->Level[NearbyIndex] = GameState->Level[Indices[I]];
		if (IsPlayer(GameState->Level[Indices[I]]))
		{
			GameState->PlayerIndex = NearbyIndex;
		}
		else if (IsSpecialBlock(GameState->Level[Indices[I]]))
		{
			OldPlayerIndex = Indices[I];
			GameState->SpecialBlockIndex = NearbyIndex;
		}
		GameState->Level[Indices[I]] = '.';
	}


	if ((Angle & 1) == 1 && AreBitsSet(GameState->GameplayFlags, SPECIAL_BLOCK_ACTIVATED))
	{
		GameState->Level[OldPlayerIndex] = 'n';
	}
}



internal u32
SetUpGravity(game_state* GameState, s32 *Indices, s32* NumIndices)
{
	s8 Blocks[100];
	s32 TempIndices[100];
	s32 TempNumIndices = 0;
	*NumIndices = 0;
	for (s32 Y = 0;
		Y < GameState->LevelSize.Y;
		++Y)
	{
		for (s32 X = 0;
			X < GameState->LevelSize.X;
			++X)
		{
			s32 Index = Y * GameState->LevelSize.X + X;
			s8 Cell = GameState->Level[Index];
			TempNumIndices = 0;
			if (IsMoveable(Cell) && IsFalling(GameState->Level, GameState->LevelSize, TempIndices, &TempNumIndices, X, Y, Cell))
			{
				Indices[(*NumIndices)++] = (u32)Index;
			}
		}
	}

	return *NumIndices;
}

internal b32
ImplementMovingRules(game_state* GameState, i2 Move)
{
	s32 Indices[100];
	s32 NumIndices;
	b32 Successful;
	if (Successful = SetUpPlayerMove(GameState, Move, Indices, &NumIndices))
	{
		PerformMove(GameState, Move, Indices, NumIndices);
	}

	return Successful;
}


enum event_type {
	NO_EVENT,
	MOVED_LATERALLY,
	MOVED_DIAGONALLY,
	CRATE_CHANGED_STATE,
	SINGLE_STEP_FALL,
	CREATURE_MOVED,
	UNDO_HAPPENED
};

internal void
CreateTransitionData(mover_data* Movers, i2 Move, s32* Indices, s32 NumIndices)
{
	FreeChunk((void*)Movers->Data);
	Movers->Data = (s32*)AllocateChunk((u32)(NumIndices * sizeof(s32)));
	Movers->Move = Move;
	Movers->NumData = NumIndices;
	for (s32 I = 0;
		I < NumIndices;
		++I)
	{
		Movers->Data[I] = Indices[I];
	}
}

internal b32
ExecuteTurn(game_state* GameState, u32 Pressed, u32 Held)
{
	i2 Move = i2{ 0,0 };

	u32 NumHeld = 0, NumPressed = 0;
	u32 Bit = 1;
	for (u32 I = 0;
		I < 4;
		++I)
	{
		if (AreBitsSet(Pressed, Bit)) ++NumPressed;
		if (AreBitsSet(Held, Bit)) ++NumHeld;
		Bit <<= 1;
	}


	if (NumHeld == 0 && NumPressed == 1)
	{
		if (AreBitsSet(Pressed, UP)) Move = i2{ 0,1 };
		else if (AreBitsSet(Pressed, DOWN)) Move = i2{ 0,-1 };
		else if (AreBitsSet(Pressed, LEFT)) Move = i2{ -1,0 };
		else if (AreBitsSet(Pressed, RIGHT)) Move = i2{ 1,0 };
	}
	else if (NumHeld == 1 && NumPressed == 0)
	{
		if (AreBitsSet(Held, UP)) Move = i2{ 0,1 };
		else if (AreBitsSet(Held, DOWN)) Move = i2{ 0,-1 };
		else if (AreBitsSet(Held, LEFT)) Move = i2{ -1,0 };
		else if (AreBitsSet(Held, RIGHT)) Move = i2{ 1,0 };
	}
	else if (NumHeld == 1 && NumPressed == 1)
	{
		if (AreBitsSet(Held, UP)) Move = i2{ 0,1 };
		else if (AreBitsSet(Held, DOWN)) Move = i2{ 0,-1 };
		else if (AreBitsSet(Held, LEFT)) Move = i2{ -1,0 };
		else if (AreBitsSet(Held, RIGHT)) Move = i2{ 1,0 };
	}


	u32 Event = NO_EVENT;
	s32 Indices[100];
	s32 NumIndices = 0;
	GameState->PreviousMove = i2{ 0,0 };

	if (ChangingCrateType(GameState, GameState->Blocks,GameState->NumBlocks))
	{
		Event = CRATE_CHANGED_STATE;
	}
	else
	{
		if (SetUpGravity(GameState, Indices, &NumIndices))
		{
			Event = SINGLE_STEP_FALL;
			Move = i2{ 0,-1 };
		}
		else
		{
			if (LengthSq(Move) > 0)
			{
				if (SetUpPlayerMove(GameState, Move, Indices, &NumIndices))
				{
					GameState->PreviousMove = Move;
					Event = MOVED_LATERALLY;
				}
				else if (NumPressed == 1 && NumHeld == 1 && AreBitsSet(GameState->GameplayFlags, DIAGONAL_MOVEMENT_ACTIVATED))
				{
					if (AreBitsSet(Pressed, UP)) Move = Move + I2(0, 1);
					else if (AreBitsSet(Pressed, DOWN)) Move = Move + I2(0, -1);
					else if (AreBitsSet(Pressed, LEFT)) Move = Move + I2(-1, 0);
					else if (AreBitsSet(Pressed, RIGHT)) Move = Move + I2(1, 0);

					if (SetUpPlayerMove(GameState, Move, Indices, &NumIndices))
					{
						GameState->PreviousMove = Move;
						Event = MOVED_DIAGONALLY;
					}
				}
			}
		}
	}

	if (NumIndices > 0)
	{
		if (GameState->UndoStack.NumWords + 2 * (NumIndices + 1) < MAX_UNDO_WORDS)
		{
			if (Event == MOVED_LATERALLY || Event == MOVED_DIAGONALLY)
			{
				PushOntoUndoStack(GameState->Level, GameState->LevelSize, Move, Indices, NumIndices, &GameState->UndoStack);
			}
			else if (Event == SINGLE_STEP_FALL)
			{
				UpdateUndoStack(GameState, GameState->Level, GameState->LevelSize, Move, Indices, NumIndices, &GameState->UndoStack);
			}

			if (Event != NO_EVENT && Event != CRATE_CHANGED_STATE)
			{
				CreateTransitionData(&GameState->Movers, Move, Indices, NumIndices);
			}


		}
		PerformMove(GameState, Move, Indices, NumIndices);
	}



	return Event;
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

	return Result;
}



void
SetupRendering(texture *Window, game_state* GameState, user_input* Input, r32 WaitTime)
{
	v2 PlayerPos = V2((s32)(GameState->PlayerIndex%GameState->LevelSize.X), (s32)(GameState->PlayerIndex / GameState->LevelSize.X)) + V2(0.5f, 0.5f);
	v2 OldPlayerPos = PlayerPos - V2(GameState->PreviousMove);



	//GameState->Screen.P = (PlayerPos-0.5f*GameState->Screen.Size);
	GameState->Screen.P = 0.95f*GameState->Screen.P + 0.05f*(PlayerPos - 0.5f*GameState->Screen.Size);




	//DrawRect(*Window, GameState->Screen, CenterDim(OldPlayerPos, v2{ 1.0f,1.0f }), v4{ 1.0f,0.0f,0.0f,1.0f });
	//DrawRect(*Window, GameState->Screen, CenterDim(PlayerPos, v2{ 1.0f,1.0f }), v4{ 0.0f,1.0f,0.0f,1.0f });

	b2 Bounds = B2(GameState->Screen);

	Bounds.X -= 1;
	Bounds.Y -= 1;
	Bounds.W += 2;
	Bounds.H += 2;
	if (Bounds.X < 0) Bounds.X = 0;
	if (Bounds.Y < 0) Bounds.Y = 0;
	if (Bounds.W + Bounds.X >= GameState->LevelSize.X) Bounds.W = GameState->LevelSize.X - Bounds.X;
	if (Bounds.H + Bounds.Y >= GameState->LevelSize.Y) Bounds.H = GameState->LevelSize.Y - Bounds.Y;


	i2 SunPos = { 15,15 };


	al_clear_to_color(al_map_rgb(0, 0, 0));




	texture Texture;
	Texture.Angle = 0.0f;
	Texture.Center = v2{ 16.0f,16.0f };
	Texture.Flags = 0;
	Texture.Region = r2{ 0.0f,0.0f,32.0f,32.0f };
	Texture.Tint = al_map_rgba(255, 255, 255, 255);


	if (GameState->RecentEvent != NO_EVENT && GameState->RecentEvent != CRATE_CHANGED_STATE)
	{
		r32 T = GameState->AgainTime / WaitTime;
		//printf("\nT = %f", T);
		//printf("\nAgainTime = %f", GameState->AgainTime);
		//printf("\nWaitTime = %f", WaitTime);
		for (s32 I = 0;
			I < GameState->Movers.NumData;
			++I)
		{
			v2 StartPos = V2(I2((u32)GameState->Movers.Data[I], GameState->LevelSize.X));
			v2 EndPos = V2(I2((u32)GameState->Movers.Data[I], GameState->LevelSize.X) + GameState->Movers.Move);


			//DrawRect(*Window, GameState->Screen, R2(StartPos, v2{ 1.0f,1.0f }), v4{ 1.0f,0.0f,0.0f,1.0f });
			//DrawRect(*Window, GameState->Screen, R2(EndPos, v2{ 1.0f,1.0f }), v4{ 0.0f,1.0f,0.0f,1.0f });


			v2 MidPos = Lerp(StartPos, T, EndPos);

			Texture.Rect = R2(MidPos, V2(1.0f, 1.0f));
			Texture.Rect.Y = 2.0f*GameState->Screen.Y + GameState->Screen.H - Texture.Rect.Y - 1.0f;
			s32 CurrentIndex = ((GameState->Movers.Data[I] / GameState->LevelSize.X) + GameState->Movers.Move.Y)*GameState->LevelSize.X + (GameState->Movers.Data[I] % GameState->LevelSize.X) + GameState->Movers.Move.X;
			s8 Field = GameState->Level[CurrentIndex];
			if (IsPlayer(Field))
			{
				s32 Index = PLAYER_NORMAL_TEXTURE;
				Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
				DrawRect(*Window, GameState->Screen, Texture);
			}
			else if (IsChebyshevCrate(Field))
			{

				s32 Index = CHEBYSHEV_BLOCK_TEXTURE;
				Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
				DrawRect(*Window, GameState->Screen, Texture);
			}
			else if (IsSpecialBlock(Field))
			{
				if (Field == 'n')
				{

				}
				else
				{

				}
			}
			else if (IsMetriclessCrate(Field))
			{
				s32 Index = METRICLESS_BLOCK_TEXTURE;
				Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
				DrawRect(*Window, GameState->Screen, Texture);
			}

		}
	}




	for (s32 Y = Bounds.Y;
		Y < Bounds.Y + Bounds.H;
		++Y)
	{
		for (s32 X = Bounds.X;
			X < Bounds.X + Bounds.W;
			++X)
		{
			s32 CurrentIndex = Y * GameState->LevelSize.X + X;
			s32 MoveIndex = (Y - GameState->PreviousMove.Y)*GameState->LevelSize.X + X - GameState->PreviousMove.X;
			s8 Field = GameState->Level[CurrentIndex];
			Texture.Rect = r2{ (r32)X,(r32)Y,1.0f,1.0f };
			Texture.Rect.Y = 2.0f*GameState->Screen.Y + GameState->Screen.H - Texture.Rect.Y - 1.0f;

			if (IsChebyshevWall(Field))
			{
				s32 Index = CHEBYSHEV_WALL_TEXTURE;
				Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
				DrawRect(*Window, GameState->Screen, Texture);
			}
			else if (IsPlayer(Field))
			{
				s32 Index = GRID_TEXTURE;
				Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
				DrawRect(*Window, GameState->Screen, Texture);
				if (!AlreadyTagged(GameState->Movers.Data, GameState->Movers.NumData, CurrentIndex)
					&& !AlreadyTagged(GameState->Movers.Data, GameState->Movers.NumData, MoveIndex))
				{
					Index = PLAYER_NORMAL_TEXTURE;
					Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
					DrawRect(*Window, GameState->Screen, Texture);
				}
			}
			else if (IsChebyshevCrate(Field))
			{
				if (!AlreadyTagged(GameState->Movers.Data, GameState->Movers.NumData, CurrentIndex)
					&& !AlreadyTagged(GameState->Movers.Data, GameState->Movers.NumData, MoveIndex))
				{
					s32 Index = CHEBYSHEV_BLOCK_TEXTURE;
					Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
					DrawRect(*Window, GameState->Screen, Texture);
				}
				else
				{
					s32 Index = GRID_TEXTURE;
					Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
					DrawRect(*Window, GameState->Screen, Texture);
				}
			}
			else if (IsMetriclessWall(Field))
			{
				s32 Index = METRICLESS_WALL_TEXTURE;
				Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
				DrawRect(*Window, GameState->Screen, Texture);
			}
			else if (IsSpecialBlock(Field))
			{

			}
			else if (IsMetriclessCrate(Field))
			{
				if (!AlreadyTagged(GameState->Movers.Data, GameState->Movers.NumData, CurrentIndex)
					&& !AlreadyTagged(GameState->Movers.Data, GameState->Movers.NumData, MoveIndex))
				{
					s32 Index = METRICLESS_BLOCK_TEXTURE;
					Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
					DrawRect(*Window, GameState->Screen, Texture);
				}
				else
				{
					s32 Index = GRID_TEXTURE;
					Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
					DrawRect(*Window, GameState->Screen, Texture);
				}
			}
			else if (IsEmpty(Field))
			{
				s32 Index = GRID_TEXTURE;
				Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
				DrawRect(*Window, GameState->Screen, Texture);
			}
		}
	}



	s32 Index = EMPTY_TEXTURE;
	Texture.Bitmap = GameState->TextureGroup.Textures[Index].Bitmap;
	Texture.Rect = r2{ GameState->Screen.P.X + 1.0f,GameState->Screen.P.Y + 0.0f,1.0f,1.0f };
	if (Input->Up.Pressed)
	{

		Texture.Tint = al_map_rgb(0, 255, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}
	else
	{
		Texture.Tint = al_map_rgb(255, 0, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}

	Texture.Rect = r2{ GameState->Screen.P.X + 1.0f,GameState->Screen.P.Y + 1.0f,1.0f,1.0f };
	if (Input->Down.Pressed)
	{

		Texture.Tint = al_map_rgb(0, 255, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}
	else
	{
		Texture.Tint = al_map_rgb(255, 0, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}

	Texture.Rect = r2{ GameState->Screen.P.X + 0.0f,GameState->Screen.P.Y + 1.0f,1.0f,1.0f };
	if (Input->Left.Pressed)
	{

		Texture.Tint = al_map_rgb(0, 255, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}
	else
	{
		Texture.Tint = al_map_rgb(255, 0, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}


	Texture.Rect = r2{ GameState->Screen.P.X + 2.0f,GameState->Screen.P.Y + 1.0f,1.0f,1.0f };
	if (Input->Right.Pressed)
	{

		Texture.Tint = al_map_rgb(0, 255, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}
	else
	{
		Texture.Tint = al_map_rgb(255, 0, 0);
		DrawRect(*Window, GameState->Screen, Texture);
	}

	al_flip_display();
}


internal void
GameUpdateAndRender(texture *Window, game_state *GameState, user_input *Input)
{


	i2 Move = { 0 };
	r32 AgainTime = 0.1f;
	u32 Pressed = 0, Held = 0;


	if (Input->Up.Pressed)
	{
		if (Input->Up.TimeHeld == 0.0f)
		{
			Pressed |= UP;
		}
		else
		{
			Held |= UP;
		}
	}
	
	if (Input->Down.Pressed)
	{
		if (Input->Down.TimeHeld == 0.0f)
		{
			Pressed |= DOWN;
		}
		else
		{
			Held |= DOWN;
		}
	}

	if (Input->Left.Pressed)
	{
		if (Input->Left.TimeHeld == 0.0f)
		{
			Pressed |= LEFT;
		}
		else
		{
			Held |= LEFT;
		}
	}

	if (Input->Right.Pressed)
	{
		if (Input->Right.TimeHeld == 0.0f)
		{
			Pressed |= RIGHT;
		}
		else
		{
			Held |= RIGHT;
		}
	}


	b32 UndoHappened = false;
	if (GameState->UndoStack.NumEntries > 0)
	{
		if (Input->Undo.Pressed)
		{
			if (Input->Undo.TimeHeld == 0.0f)
			{
				UndoTurn(GameState, GameState->Level, GameState->LevelSize, &GameState->UndoStack);
				++GameState->UndoCount;
				UndoHappened = true;
				GameState->Movers.NumData = 0;
			}
			else
			{
				r32 TimeToWait = GetUndoWaitTime(GameState->UndoCount);
				if (Input->Undo.TimeHeld >= TimeToWait)
				{
					UndoTurn(GameState, GameState->Level, GameState->LevelSize, &GameState->UndoStack);
					Input->Undo.TimeHeld -= TimeToWait;
					++GameState->UndoCount;
					UndoHappened = true;
					GameState->Movers.NumData = 0;
				}
			}
		}
		else
		{
			GameState->UndoCount = 0;
		}

		//TODO(ian): Put undo here?
	}
	else
	{
		GameState->UndoCount = 0;
	}



	//TODO(ian): Make the Coordinate System normal
	if (!Pressed && Held)
	{
		if (AreBitsSet(Held, UP))
		{
			Move = i2{ 0,1 };
		}

		if (AreBitsSet(Held, DOWN))
		{
			Move = i2{ 0,-1 };
		}

		if (AreBitsSet(Held, LEFT))
		{
			Move = i2{ -1,0 };
		}

		if (AreBitsSet(Held, RIGHT))
		{
			Move = i2{ 1,0 };
		}
	}
	else
	{
		if (AreBitsSet(Pressed, UP))
		{
			Move = i2{ 0,1 };
		}

		if (AreBitsSet(Pressed, DOWN))
		{
			Move = i2{ 0,-1 };
		}

		if (AreBitsSet(Pressed, LEFT))
		{
			Move = i2{ -1,0 };
		}

		if (AreBitsSet(Pressed, RIGHT))
		{
			Move = i2{ 1,0 };
		}
	}

	GameState->AgainTime += Input->dt;
	r32 WaitTime = GetEventWaitTime(GameState->RecentEvent);

	if (GameState->AgainTime >= WaitTime && GameState->UndoCount == 0)
	{
		//printf("\nBeforeExecutingTurn:\n%s", GameState->Level);
		if (GameState->RecentEvent != NO_EVENT && GameState->RecentEvent != CRATE_CHANGED_STATE && GameState->RecentEvent != UNDO_HAPPENED)
		{
			//PerformMove(GameState, GameState->Movers.Move, GameState->Movers.Data, GameState->Movers.NumData);
		}
		GameState->Movers.NumData = 0;
		GameState->RecentEvent = ExecuteTurn(GameState, Pressed, Held);
		if (WaitTime > 0.0f)
		{
			GameState->AgainTime -= WaitTime;
		}
		else
		{
			GameState->AgainTime = Input->dt;
		}
	}
	else
	{
		if (GameState->UndoCount != 0)
		{
			GameState->RecentEvent = NO_EVENT;
		}
	}
	WaitTime = GetEventWaitTime(GameState->RecentEvent);

	//printf("\nBefore Rendering:\n%s", GameState->Level);

	SetupRendering(Window, GameState, Input, WaitTime);

}


s32
InitializeGame(FILE* Log,game_state* GameState)
{
	GameState->Screen = R2(v2{ 0.0f,0.0f }, v2{ 32.0f,18.0f });;
	GameState->AgainTime = 0.0f;
	Seed(&GameState->PRNG, 100);

	fprintf(Log, "\nLoading Textures...");

	s32 Index = PLAYER_NORMAL_TEXTURE;
	GameState->TextureGroup.Textures[Index].Bitmap = al_load_bitmap("art\\hydra4.png");

	if (GameState->TextureGroup.Textures[Index].Bitmap == NULL)
	{
		int u = 7;
	}


	Index = CHEBYSHEV_WALL_TEXTURE;
	GameState->TextureGroup.Textures[Index].Bitmap = al_load_bitmap("art\\dngn_metal_wall.png");

	if (GameState->TextureGroup.Textures[Index].Bitmap == NULL)
	{
		int u = 7;
	}


	Index = METRICLESS_WALL_TEXTURE;
	GameState->TextureGroup.Textures[Index].Bitmap = al_load_bitmap("art\\wall_yellow_rock0.png");


	if (GameState->TextureGroup.Textures[Index].Bitmap == NULL)
	{
		int u = 7;
	}

	Index = CHEBYSHEV_BLOCK_TEXTURE;
	GameState->TextureGroup.Textures[Index].Bitmap = al_load_bitmap("art\\alive-block1.png");


	if (GameState->TextureGroup.Textures[Index].Bitmap == NULL)
	{
		int u = 7;
	}


	Index = METRICLESS_BLOCK_TEXTURE;
	GameState->TextureGroup.Textures[Index].Bitmap = al_load_bitmap("art\\dngn_transparent_wall.png");

	if (GameState->TextureGroup.Textures[Index].Bitmap == NULL)
	{
		int u = 7;
	}

	Index = EMPTY_TEXTURE;
	GameState->TextureGroup.Textures[Index].Bitmap = al_load_bitmap("art\\empty.png");



	Index = GRID_TEXTURE;
	GameState->TextureGroup.Textures[Index].Bitmap = al_load_bitmap("art\\grid_block.png");



	if (GameState->TextureGroup.Textures[Index].Bitmap == NULL)
	{
		int u = 7;
	}


	//TODO(ian): make sure all of the textures load correctly!!!!

	fprintf(Log, "Successful\n");

	GameState->AgainTime = 0.0f;
	GameState->UndoCount = 0;
	GameState->PreviousMove = i2{ 1,0 };
	GameState->SpecialBlockIndex = -1;
	GameState->GameplayFlags = SPECIAL_BLOCK_ACTIVATED | DIAGONAL_MOVEMENT_ACTIVATED;


	//NOTE(ian): high concept pitch: a cross between catherine and snakebird
	//16bit
	//TODO(ian): should I use a char code:
	//0 - static
	//1 - right
	//2 - up right
	//3 - up
	//4 - up left
	//5 - left
	//6 - down left
	//7 - down
	//8 - down right
	//p - player * 9
	//l - LMover * 9
	//j - JMover * 9
	//b - chebyshev block * 9
	//d - metricless block * 9


	//TODO(ian): make level editor!!! support a big world!!!!
	//Number of puzzles so far: ~37

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
	"s......sxb.....s"
	"s......sx......s"
	"s......sx......s"
	"s......sx......s"
	"s......sx......s"
	"s......sx..bp..s"
	"s......sxxxxxxxs"
	"ssssssssssssssss";

	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s......bbbb....s"
	"s......bxb.....s"
	"s......bb......s"
	"s...bbbb......xs"
	"s...bxb......x.s"
	"s.bbbb....b.x..s"
	"s.bxb......x...s"
	"s.bb....b.x....s"
	"s.b......x.....s"
	"sb....b.x......s"
	"s......x.......s"
	"s....px........s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";

	/*

	const char* Level =
	"ssssssssssssssss"
	"ssssssssssssssss"
	"s..............s"
	"spb.b..........s"
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

	*/


	/*
	const char* Level =
	"ssssssssssssssss"
	"s...x..........s"
	"s......x......xs"
	"s..............s"
	"s..x......x....s"
	"s..............s"
	"s..............s"
	"s.........x....s"
	"s..............s"
	"s......x......xs"
	"s..............s"
	"s...x.....x....s"
	"s..............s"
	"sp.............s"
	"sxxxxxxxxxxxxxxx"
	"ssssssssssssssss";

	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"sxxxx..........s"
	"s...x..........s"
	"s.......x......s"
	"s..............s"
	"s..............s"
	"sp...b.........s"
	"sxxxxxxxx......s"
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	const char* Level =
	"ssssssssssssssss"
	"s...x..........s"
	"s...x..........s"
	"s...x..........s"
	"s...x..........s"
	"s..............s"
	"s..............s"
	"sp...........b.s"
	"sxxxxxxxxxxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	const char* Level =
	"ssssssssssssssss"
	"s...x..........s"
	"s...x..........s"
	"s...x..........s"
	"s..............s"
	"s..............s"
	"s..............s"
	"sp...........b.s"
	"sxxx..xxxxxxxxxs"
	"s..xxxx........s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s........xxxxxxs"
	"s........x.....s"
	"sp.......x.....s"
	"sxxxxxxxxx.....s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
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
	"s....bxb.......s"
	"s.....xxx......s"
	"s....bx........s"
	"sp......x......s"
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
	"s..bx..x..xb...s"
	"s..............s"
	"s............p.s"
	"sxxxxxxbxxxxxxxs"
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
	"s.x..b.........s"
	"s.xxxxx........s"
	"s.xx...........s"
	"s.x........xxxxs"
	"s.x............s"
	"s.x............s"
	"s.p.b..........s"
	"sxxxxxx........s"
	"s..............s"
	"ssssssssssssssss";

	/*
	//TODO(ian): this is much better! Keep/iterate
	const char* Level =
	"ssssssssssssssss"
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s.....s.b.bp...s"
	"s.......xxxxxxxs"
	"s.......xxxxxxxs"
	"s.........xxxxxs"
	"s..........xxxxs"
	"s...........xxxs"
	"s............xxs"
	"s.............xs"
	"sxxxx..........s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	*/

	/*
	//TODO(ian): this is much better! Keep/iterate
	const char* Level =
	"ssssssssssssssss"
	"s...xxxxxxxx...s"
	"s..pxxxxxxxx...s"
	"s...xxxxxxxx...s"
	"s...xxxxxxxx...s"
	"s...b......b...s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"sxxxxxxxxxxxxxxs"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	*/
	/*
	//TODO(ian): split into two puzzles!!
	const char* Level =
	"ssssssssssssssss"
	"s...xxxxxxxx...s"
	"s..pxxxxxxxx...s"
	"s...xxxxxxxx...s"
	"s...xxxxxxxx...s"
	"s...b......b...s"
	"s..............s"
	"s..............s"
	"ssss........ssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"sxxxxxxxxxxxxxxs"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

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
	"sx..b..b.......s"
	"sx..xxxxxxxxxxxs"
	"sxxxxxxxx......s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";


	*/
	/*
	//TODO(ian): need to find out whether the diagonal control scheme is simple enough to be found out by accident!!
	//NOTE(ian): this is pretty good. Keep/iterate upon this concept!!!
	const char* Level =
	"ssssssssssssssss"
	"s,,,,,,,,......s"
	"s..............s"
	"s......bb......s"
	"sp......b......s"
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

	/*
	const char* Level =
	"ssssssssssssssss"
	"s,,,,,,,,......s"
	"s..............s"
	"s..............s"
	"sp....b.b......s"
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
	"s..............s"
	"sxsssxxxxxxxxxxs"
	"s........xssssss"
	"s........x..s..s"
	"s..............s"
	"s....b........xs"
	"sx..b.b..xxs.sss"
	"sx...b...xssssss"
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
	"ssssss......b..s"
	"s..........b...s"
	"sxs.ssss..b....s"
	"sxxssssssssxxxxs"
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
	"sxxxxxx..xb....s"
	"sssssx....ss...s"
	"s..............s"
	"s....xssssssssss"
	"s.b.xxxxxxxxxxxs"
	"sp.xxxxxxxxxxxxs"
	"sxxxxxxxxxxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"ssssssssssssssss";

	*//*
	//TODO(ian): this is bad?
	const char* Level =
	"ssssssssssssssss"
	"s.......x......s"
	"s.............xs"
	"s....s.......x.s"
	"s...sbs.....x..s"
	"s....s.....x...s"
	"s...sbs...x....s"
	"s....s...x.....s"
	"s...sbs.x......s"
	"s....s.x.......s"
	"s.....x........s"
	"sxxxxx.........s"
	"s.b.b.b........s"
	"sp.............s"
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
	"sp..b.b...s....s"
	"sxxxxxxxs......s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s.............bs"
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
	"s............p.s"
	"s...........xxxs"
	"s...........s..s"
	"s......d....s..s"
	"s......d....s..s"
	"s.sb.bbbbbsxx..s"
	"s.sbbbsssbssssss"
	"sxssss.sbbbs..ss"
	"s...ss.sssss..ss"
	"s..........xxxxs"
	"ssssssssssssssss";


	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s..............s"
	"s..............s"
	"spb.b..........s"
	"sxxxxx......sxxxs"
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
	"s......b.......s"
	"s.xbx.xbx.xbx.xs"
	"s..p...........s"
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
	"sxx....x..bxxxbs"
	"sss....x.......s"
	"sss....x......ps"
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
	"sb..........x..s"
	"s.b........xxx.s"
	"s..b....p.xxxxxs"
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
	"s.xb...bxs.....s"
	"s.x.b.b.xs.....s"
	"s.x.....xs.....s"
	"sxx.....xs.....s"
	"sp......xs.....s"
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
	"s.......b......s"
	"s..p...b.......s"
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
	"s.......b......s"
	"sp...x..bbb.xx.s"
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
	"s...b...xxxx..ss"
	"sxxx..xxxssss..s"
	"s..xb.x..s..s..s"
	"sp....x..s..s..s"
	"sxxxxxx.....s..s"
	"ssssssssssssssss";

	/*

	const char* Level =
	"ssssssssssssssss"
	"sx.............s"
	"sx.............s"
	"sx.........x...s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx....x........s"
	"sx.............s"
	"sx.......b.b...s"
	"sx..p...b...b..s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";


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
	"s...s.bbb..s...s"
	"s...s.x....s...s"
	"s...s..p...s...s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s.b.b..........s"
	"spb.b.b........s"
	"sxxxxx.........s"
	"ssss...........s"
	"s..............s"
	"sx.............s"
	"s.............xs"
	"s..............s"
	"s...........ddds"
	"sbd.......ddddds"
	"sbd.......ddddds"
	"sbbbbbbbbbbbbbbs"
	"ssssssssssssssss";

	*/

	/*

	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s.....b........s"
	"s....x.........s"
	"s...x..........s"
	"s..x...........s"
	"s.x............s"
	"s..............s"
	"sp....b........s"
	"sxxssbbbbb.....s"
	"sxxxssssss.....s"
	"s........s.....s"
	"s........s.....s"
	"s........s.....s"
	"s........sxxxxxs"
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
	"s.p.b.b.b......s"
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
	"s.........d....s"
	"s.........d....s"
	"s.........d....s"
	"s.........d....s"
	"s.........d.p..s"
	"sbssssdsdsdsbxxs"
	"sxsssss.s.s.sbbs"
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
	"s.b............s"
	"sxxxxx.........s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sp.............s"
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
	"s.......b.b.b..s"
	"sp......x.x.x..s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";


	*/

	//NOTE(ian): Special Block Levels: ~9


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
	"s.......x..bp..s"
	"sxssssbxxxxxxxxs"
	"sxssssxxxxxxxxxs"
	"s..............s"
	"ssssssssssssssss";

	*/
	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"sx.............s"
	"s..............s"
	"s..........bpb.s"
	"sb.b.b.b.b.xxxxs"
	"ss.s.s.sssssssss"
	"ss.s.s.sbbbs..ss"
	"ss.s.s.sssss..ss"
	"ssssssss...xxxxs"
	"ss.s...........s"
	"ss.s...........s"
	"ss.s...........s"
	"ss.s...........s"
	"ssssssssssssssss";


	/*
	const char* Level =
	"ssssssssssssssss"
	"sx.............s"
	"sx........b.p..s"
	"s.......xxxxxxxs"
	"s..............s"
	"s..............s"
	"s..............s"
	"sx.............s"
	"sx....b........s"
	"sx....d....xxxxs"
	"sx..ddddd..sssss"
	"sx..ddddds.sssss"
	"sx.sdsdsds.sssss"
	"ss.sdsdsssssssss"
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
	"ss..b..........s"
	"s.pb...........s"
	"sxxxxs....sxxxxs"
	"s...xs.b..ssssss"
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
	"s.....bxs....xxs"
	"s.....bxs....sss"
	"s......xs....sss"
	"s......xs....sss"
	"s.....pxssssssss"
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
	"s...sssb......ps"
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
	"s.p...b.x......s"
	"s.x.x.x.x.x.x.xs"
	"sxxxxxxxxxxxxxxx"
	"ssssssssssssssss";


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
	"s.p...b.x......s"
	"s.x.x.x.x.x.x.xs"
	"sxxxxxxxxxxxxxxx"
	"ssssssssssssssss";


	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s.b.b..........s"
	"spb.b.b........s"
	"sxxxxx.........s"
	"ssss...........s"
	"s..............s"
	"s..............s"
	"sx.............s"
	"s.............xs"
	"s..............s"
	"s...........ddds"
	"sbd.......ddddds"
	"sbd.......ddddds"
	"sbbbbbbbbbbbbbbs"
	"ssssssssssssssss";


	/*
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
	"s..p...x.......s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";

	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s...........x..s"
	"s..............s"
	"s..............s"
	"s..............s"
	"s......xxxxxxsss"
	"s......x.......s"
	"s..p...x.......s"
	"sxxxxxxxxxxxxxxs"
	"s.....s.xxxxxxxs"
	"s.........xxxxxs"
	"s.........xxxxxs"
	"s...........xxxs"
	"s...........xxxs"
	"ssssssssssssssss";

	*/
	/*
	const char* Level =
	"ssssssssssssssss"
	"s.....sxxxxxxxxs"
	"s..............s"
	"s..........p...s"
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
	"s.......b..p...s"
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
	"s...........b..s"
	"s..........b...s"
	"s...........bp.s"
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
	"s..sss......b..s"
	"sx.........b...s"
	"sx..........bp.s"
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
	"sb..........bx.s"
	"sx...........p.s"
	"sx..........bx.s"
	"s.s.......xxxxxs"
	"sx........ssssss"
	"sx........ssssss"
	"sx.....s.......s"
	"sx....bs.......s"
	"sx....ss.......s"
	"sx...xxxxxxxxxxs"
	"sx....x........s"
	"ssssssssssssssss";

	/*
	const char* Level =
	"ssssssssssssssss"
	"sxbb......xxxxxs"
	"sbxb...........s"
	"sb.b......xxxx.s"
	"sb..........bx.s"
	"sx...........p.s"
	"sx..........bx.s"
	"sx........xxxxxs"
	"sx........ssssss"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sx.............s"
	"sxxxx.......xxxs"
	"s..............s"
	"ssssssssssssssss";


	/*
	//NOTE(ian): this is a neat idea and it's much better! :)
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s..............s"
	"s.......b......s"
	"s......b.......s"
	"s.......b...p..s"
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
	"s...b..........s"
	"s..b......bb...s"
	"s..b.b.....pb..s"
	"s...b.b....b...s"
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
	"s....s.....b...s"
	"s....s....b....s"
	"s....s....pbbsss"
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
	"s...........b..s"
	"s..........b...s"
	"s........b..b.ps"
	"s........xxxxxxs"
	"s........s.....s"
	"s......sss.....s"
	"s......s.......s"
	"s....sss.......s"
	"s....s.........s"
	"s..sss.........s"
	"ssssssssssssssss";

	/*
	const char* Level =
	"ssssssssssssssss"
	"s...s..........s"
	"s...s..........s"
	"s.sss..........s"
	"s.s............s"
	"sss.........b..s"
	"s..........b...s"
	"s........b..b.ps"
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
	"s.xxxxxssbssxxxs"
	"s.x.....bsssssss"
	"s.xxxxsss..bb..s"
	"s..bbb...sssxx.s"
	"s.xxxxsss....x.s"
	"s.x..........x.s"
	"s.x..........x.s"
	"s.xxxxxxxxxxxx.s"
	"s..............s"
	"s.......x......s"
	"s.......x......s"
	"sp......x......s"
	"sxxxxxxxxxxxxxxs"
	"ssssssssssssssss";




	/*



	//NOTE(ian): hard level but it's not about something fundamental
	const char* Level =
	"ssssssssssssssss"
	"s....x.........s"
	"s..............s"
	"s..............s"
	"s..............s"
	"sxxx...xxxxxxxxs"
	"sxbb...bbxxxxxxs"
	"sxxx...xxxxxxxxs"
	"s..............s"
	"s...b..b.......s"
	"s....x.x.......s"
	"s...b...b......s"
	"s...x...x......s"
	"sp.............s"
	"sxxxxxxxxxxxxxxs"
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
	"s.....xxxxxxxxxs"
	"s..x...........s"
	"s.....xxxxxxxxxs"
	"s..............s"
	"s..xbb.........s"
	"s..............s"
	"sp.............s"
	"sxxxxxxxxxxxxxxx"
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
	"s..b...........s"
	"s..x...........s"
	"s..b...........s"
	"s..............s"
	"sp...........s.s"
	"sxxs.bbbbbbbbsxs"
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
	"s....s.........s"
	"s..............s"
	"s...b..........s"
	"s...b..........s"
	"sp..bx.........s"
	"sxxxxx.........s"
	"ssssssssssssssss";











	*/

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






	/*
	const char* Level =
	"ssssssssssssssss"
	"s..............s"
	"s.b.b..b....p..s"
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








	GameState->PlayerIndex = -1;

	fprintf(Log, "Loading \'world_map.txt\'...");
	ALLEGRO_FILE* F = al_fopen("levels\\level2.txt", "r");
	if (F == NULL)
	{
		fprintf(Log, "Failed: Couldn't open file.");
		return -1;
	}
	int64_t FSize = al_fsize(F);
	GameState->Level = (s8*)AllocateChunk(FSize + 1);
	assert(GameState->Level);
	al_fread(F, (void*)GameState->Level, FSize);
	GameState->Level[FSize] = 0;
	al_fclose(F);

	GameState->LevelSize = i2{ 0,0 };
	GameState->NumBlocks = 0;
	for (s32 I = 0;
		I < (s32)FSize;
		++I)
	{
		if (GameState->Level[I] == '\n')
		{
			if (GameState->LevelSize.X == 0)
			{
				GameState->LevelSize.X = I + 1;
			}
			else
			{
				if (((I % GameState->LevelSize.X) + 1) != GameState->LevelSize.X)
				{
					fprintf(Log, "Failed: world is not rectangular");
					return -1;
				}
			}
			++GameState->LevelSize.Y;
		}
		else if (IsMoveable(GameState->Level[I]))
		{
			//NOTE(ian): this assumes that LevelSize.X is known which assumes the top row of the world has no movers!
			GameState->Blocks[GameState->NumBlocks].Pos = I2((u32)I,GameState->LevelSize.X);
			GameState->Blocks[GameState->NumBlocks].Move = i2{ 0,0 };
			GameState->Blocks[GameState->NumBlocks].Rect = R2(V2(GameState->Blocks[GameState->NumBlocks].Pos), v2{ 1.0f,1.0f });
			GameState->Blocks[GameState->NumBlocks].Type = (s32)GameState->Level[I];
			GameState->Level[I] = InitializeEmpty();
			++GameState->NumBlocks;
		}
	}

	//printf("\nLength of Level = %d", strlen((char*)GameState->Level));

	if ((FSize) != (GameState->LevelSize.X + 1) * GameState->LevelSize.Y)
	{
		fprintf(Log, "Failed: \'world_map.txt\' is not formatted correctly");
		return -1;
	}


	fprintf(Log, "Successful\n");

	s32 HalfNumRows = (GameState->LevelSize.Y / 2);
	for (s32 Y = 0;
		Y < HalfNumRows;
		++Y)
	{
		for (s32 X = 0;
			X < GameState->LevelSize.X;
			++X)
		{
			s32 TopIndex = Y * GameState->LevelSize.X + X;
			s32 BottomIndex = (GameState->LevelSize.Y - Y - 1)*GameState->LevelSize.X + X;
			s8 Temp = GameState->Level[TopIndex];
			GameState->Level[TopIndex] = GameState->Level[BottomIndex];
			GameState->Level[BottomIndex] = Temp;
		}
	}

	fprintf(Log, "Searching for player...");
	b32 FoundPlayer = false;
	for (s32 Y = 0;
		Y < GameState->LevelSize.Y;
		++Y)
	{
		for (s32 X = 0;
			X < GameState->LevelSize.X;
			++X)
		{
			s32 Index = Y * GameState->LevelSize.X + X;
			if (IsPlayer(GameState->Level[Index]))
			{
				GameState->Screen.P = V2(X, Y) - (0.5f*GameState->Screen.Size) + V2(0.5f, 0.5f);
				GameState->PlayerIndex = Index;
				FoundPlayer = true;
				break;
			}
		}
		if (FoundPlayer)
		{
			break;
		}
	}

	//printf("\n%s", GameState->Level);

	if (GameState->PlayerIndex != -1)
	{
		fprintf(Log, "Player Found\n");
	}
	else
	{
		fprintf(Log, "Failed");
		return -1;
	}

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

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_new_window_title("Sokovania");

	Display = al_create_display(WindowSize.X, WindowSize.Y);
	if (!Display)
	{
		fprintf(Log, "Failed to create display!");
		return -1;
	}

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



	fprintf(Log, "Successful");

	ALLEGRO_KEYBOARD_STATE KeyboardState;

	al_register_event_source(EventQueue, al_get_display_event_source(Display));
	al_register_event_source(EventQueue, al_get_timer_event_source(Timer));
	al_register_event_source(EventQueue, al_get_timer_event_source(FrameRate));
	al_register_event_source(EventQueue, al_get_keyboard_event_source());

	al_set_target_bitmap(al_get_backbuffer(Display));

	user_input Input = {};

	Input.dt = 1.0f / FPS;

	Input.Up.KeyOne = ALLEGRO_KEY_UP;
	Input.Up.KeyTwo = ALLEGRO_KEY_W;

	Input.Down.KeyOne = ALLEGRO_KEY_DOWN;
	Input.Down.KeyTwo = ALLEGRO_KEY_S;


	Input.Left.KeyOne = ALLEGRO_KEY_LEFT;
	Input.Left.KeyTwo = ALLEGRO_KEY_A;


	Input.Right.KeyOne = ALLEGRO_KEY_RIGHT;
	Input.Right.KeyTwo = ALLEGRO_KEY_D;


	Input.Undo.KeyOne = ALLEGRO_KEY_Z;
	Input.Undo.KeyTwo = ALLEGRO_KEY_U;

	Input.Restart.KeyOne = ALLEGRO_KEY_R;
	Input.Restart.KeyTwo = ALLEGRO_KEY_R;

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
		al_get_keyboard_state(&KeyboardState);
		if (Ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		else if (Ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			if (Ev.keyboard.keycode == Input.Up.KeyOne || Ev.keyboard.keycode == Input.Up.KeyTwo)
			{
				++Input.Up.NumPresses;
				Input.Up.Pressed = true;
				Input.Up.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Down.KeyOne || Ev.keyboard.keycode == Input.Down.KeyTwo)
			{
				++Input.Down.NumPresses;
				Input.Down.Pressed = true;
				Input.Down.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Left.KeyOne || Ev.keyboard.keycode == Input.Left.KeyTwo)
			{
				++Input.Left.NumPresses;
				Input.Left.Pressed = true;
				Input.Left.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Right.KeyOne || Ev.keyboard.keycode == Input.Right.KeyTwo)
			{
				++Input.Right.NumPresses;
				Input.Right.Pressed = true;
				Input.Right.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Undo.KeyOne || Ev.keyboard.keycode == Input.Undo.KeyTwo)
			{
				++Input.Undo.NumPresses;
				Input.Undo.Pressed = true;
				Input.Undo.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Restart.KeyOne || Ev.keyboard.keycode == Input.Restart.KeyTwo)
			{
				++Input.Restart.NumPresses;
				Input.Restart.Pressed = true;
				Input.Restart.TimeHeld = 0.0f;
			}
		}
		else if (Ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (Ev.keyboard.keycode == Input.Up.KeyOne || Ev.keyboard.keycode == Input.Up.KeyTwo)
			{
				Input.Up.Pressed = false;
				Input.Up.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Down.KeyOne || Ev.keyboard.keycode == Input.Down.KeyTwo)
			{
				Input.Down.Pressed = false;
				Input.Down.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Left.KeyOne || Ev.keyboard.keycode == Input.Left.KeyTwo)
			{
				Input.Left.Pressed = false;
				Input.Left.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Right.KeyOne || Ev.keyboard.keycode == Input.Right.KeyTwo)
			{
				Input.Right.Pressed = false;
				Input.Right.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Undo.KeyOne || Ev.keyboard.keycode == Input.Undo.KeyTwo)
			{
				Input.Undo.Pressed = false;
				Input.Undo.TimeHeld = 0.0f;
			}
			else if (Ev.keyboard.keycode == Input.Restart.KeyOne || Ev.keyboard.keycode == Input.Restart.KeyTwo)
			{
				Input.Restart.Pressed = false;
				Input.Restart.TimeHeld = 0.0f;
			}
		}
		else if (Ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (Ev.timer.source == FrameRate)
			{
				if (Input.Up.NumPresses == 0)
				{
					Input.Up.TimeHeld += 1.0f / FPS;
				}

				if (Input.Down.NumPresses == 0)
				{
					Input.Down.TimeHeld += 1.0f / FPS;
				}

				if (Input.Left.NumPresses == 0)
				{
					Input.Left.TimeHeld += 1.0f / FPS;
				}

				if (Input.Right.NumPresses == 0)
				{
					Input.Right.TimeHeld += 1.0f / FPS;
				}

				if (Input.Undo.NumPresses == 0)
				{
					Input.Undo.TimeHeld += 1.0f / FPS;
				}

				if (Input.Restart.NumPresses == 0)
				{
					Input.Restart.TimeHeld += 1.0f / FPS;
				}


				GameUpdateAndRender(&GameState.Window, &GameState, &Input);

				Input.Up.NumPresses = 0;
				Input.Down.NumPresses = 0;
				Input.Left.NumPresses = 0;
				Input.Right.NumPresses = 0;
				Input.Undo.NumPresses = 0;
				Input.Restart.NumPresses = 0;



				++FramesPerSec;
			}
			else
			{
				printf("\nFPS: %d", FramesPerSec);
				FramesPerSec = 0;
			}
		}
	}

	al_destroy_display(Display);

	al_destroy_timer(Timer);
	al_destroy_timer(FrameRate);

	return 0;
}
