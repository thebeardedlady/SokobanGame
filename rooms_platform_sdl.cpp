#include "SDL.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

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
FMod(r32 Num,r32 Mod)
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
	s32 Result = Abs(A.X)+Abs(A.Y);
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


//TODO(ian): test this!!!!
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
		else if(A.Y < 0)
		{
			Result = 6;
		}
		else
		{
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
		Result = Angle/2;
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
	v2 Result = ComplexMult(A, v2{ B.X,-B.Y })/LengthSq(B);
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
	r32 Result = CLength(A-B);
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
	v2 Result = V2(CCosine(Theta), CSine(Theta)) * CLength(P-Center) + Center;
	return Result;
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
	i2 Result = Box.P + (Box.Size/2);
	return Result;
}

inline b2
CenterDim(i2 Center, i2 Size)
{
	b2 Result;
	Result.P = Center - (Size/2);
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
	s32 Result = A + (Cube(Numerator)*(D-3*C+3*B-A)+Square(Numerator)*Denominator*(3*A-6*B+3*C)
		+ Numerator*Square(Denominator)*(3*A+3*B))/Cube(Denominator);
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


inline b32
AreBitsSet(u32 Field, u32 Mask)
{
	b32 Result = ((Field & Mask) == Mask);
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





typedef struct {
	u32 *Texels;
	u32 Width;
	u32 Height;
}texture;

/*
internal void
DrawRect(texture Output, texture Input, r2 Screen, r2 Rect, r2 DrawRegion)
{
	if (Intersects(Screen, Rect))
	{
		r2 Clip = GetIntersection(Screen, Rect);
		r2 Relative = RelativeRectTransformation(Rect, Clip,DrawRegion);
		r2 Increment = 

		for (s32 Y = Clip.Y;
			Y < Clip.Y+Clip.H;
			++Y)
		{
			for (s32 X = Clip.X;
				X < Clip.X+Clip.W;
				++X)
			{
				u32 ColorValue;
				Output.Texels[Y * Output.Width + X] = Input.Texels[InputY*Input.Width + InputX];
			}

			Pos.Y += Increment.Y;
			Pos.X = (r32)InputMinX;
		}
	}
}
*/




internal void
DrawRect(texture Output, r2 Screen, r2 Rect, v4 Color)
{
	if (Intersects(Screen, Rect))
	{


		Rect = GetIntersection(Screen, Rect);

		s32 MinX, MinY, MaxX, MaxY;
		MinX = (s32)(Output.Width * ((Rect.X - Screen.X) / Screen.W));
		MinY = (s32)(Output.Height * ((Rect.Y - Screen.Y) / Screen.H));
		MaxX = (s32)(Output.Width * ((Rect.X + Rect.W - Screen.X) / Screen.W));
		MaxY = (s32)(Output.Height * ((Rect.Y + Rect.H - Screen.Y) / Screen.H));

		u32 Dest = (((u32)(255.0f * Color.R) << 16) |
			((u32)(255.0f * Color.G) << 8) |
			((u32)(255.0f * Color.B) << 0) |
			((u32)(255.0f * Color.A) << 24));


		for (s32 Y = MinY;
			Y < MaxY;
			++Y)
		{
			for (s32 X = MinX;
				X < MaxX;
				++X)
			{
				Output.Texels[Y * Output.Width + X] = Dest;
			}
		}
	}
}

internal void
DrawRect(texture Output, texture Input, r2 Screen, r2 Rect)
{
	if (Intersects(Screen, Rect))
	{
		r2 Clip = GetIntersection(Screen, Rect);


		//NOTE(ian): When changing 'Clip' to 'Rect' in the following four lines
		//the rect is drawn on the other side of the screen horizontally
		s32 MinX, MinY, MaxX, MaxY;
		MinX = (s32)(Output.Width * ((Clip.X - Screen.X) / Screen.W));
		MinY = (s32)(Output.Height * ((Clip.Y - Screen.Y) / Screen.H));
		MaxX = (s32)(Output.Width * ((Clip.X + Clip.W - Screen.X) / Screen.W));
		MaxY = (s32)(Output.Height * ((Clip.Y + Clip.H - Screen.Y) / Screen.H));

		s32 InputMinX, InputMinY, InputMaxX, InputMaxY;
		InputMinX = (s32)(Input.Width * ((Clip.X - Rect.X) / Rect.W));
		InputMinY = (s32)(Input.Height * ((Clip.Y - Rect.Y) / Rect.H));
		InputMaxX = (s32)(Input.Width * ((Clip.X + Clip.W - Rect.X) / Rect.W));
		InputMaxY = (s32)(Input.Height * ((Clip.Y + Clip.H - Rect.Y) / Rect.H));

		v2	Increment = v2{ (r32)(InputMaxX - InputMinX) / (r32)(MaxX - MinX),(r32)(InputMaxY - InputMinY) / (r32)(MaxY - MinY) };
		v2 Pos = v2{ (r32)InputMinX,(r32)InputMinY };

		s32 InputX = InputMinX,InputY = InputMinY;
		for (s32 Y = MinY;
			Y < MaxY;
			++Y)
		{
			for (s32 X = MinX;
				X < MaxX;
				++X)
			{
				InputX = (s32)Pos.X;
				InputY = (s32)Pos.Y;
				Output.Texels[Y * Output.Width + X] = Input.Texels[InputY*Input.Width+InputX];
				Pos.X += Increment.X;
			}

			Pos.Y += Increment.Y;
			Pos.X = (r32)InputMinX;
		}
	}
}



internal void
DrawChebyshevBox(texture Output, texture Input, r2 Screen, v2 Origin, r2 Box, r32 Angle, u32 Orientation) {
	
	
	v2 Corners[4];
	GetCorners(Box, Corners);

	for (s32 i = 0;
		i < 4;
		++i)
	{
		Corners[i] = CRotate(Origin, Corners[i], Angle);
	}

	r2 BoundingBox = MultiplePoints(Corners, 4);


	if (Intersects(BoundingBox, Screen))
	{
		BoundingBox = GetIntersection(BoundingBox, Screen);

		s32 MinX, MinY, MaxX, MaxY;
		MinX = (s32)(Output.Width * ((BoundingBox.X - Screen.X) / Screen.W));
		MinY = (s32)(Output.Height * ((BoundingBox.Y - Screen.Y) / Screen.H));
		MaxX = (s32)(Output.Width * ((BoundingBox.X + BoundingBox.W - Screen.X) / Screen.W));
		MaxY = (s32)(Output.Height * ((BoundingBox.Y + BoundingBox.H - Screen.Y) / Screen.H));




		BoundingBox.W /= (r32)(MaxX - MinX);
		BoundingBox.H /= (r32)(MaxY - MinY);

		v2 Point = BoundingBox.P;

		for (u32 Y = MinY;
			Y < MaxY;
			++Y)
		{
			for (u32 X = MinX;
				X < MaxX;
				++X)
			{
				v2 CRotatedPoint = CRotate(Origin, Point, -Angle);
				v2 bary = Barycentric(Box, CRotatedPoint);


				if (bary.X >= 0.0f && bary.X < 1.0f && bary.Y >= 0.0f && bary.Y < 1.0f)
				{
					if (Orientation == 0)
					{
						//NOTE(ian): Standard Orientation
					}
					else if (Orientation == 1)
					{
						r32 temp = bary.Y;
						bary.Y = 1.0f - bary.X;
						bary.X = temp;
					}
					else if (Orientation == 2)
					{
						bary.X = 1.0f - bary.X;
						bary.Y = 1.0f - bary.Y;
					}
					else
					{
						r32 temp = bary.X;
						bary.X = 1.0f - bary.Y;
						bary.Y = temp;
					}

					Output.Texels[Y*Output.Width + X] = Input.Texels[((u32)(bary.Y*Input.Height))*Input.Width + ((u32)(bary.X*Input.Width))];
				}

				Point.X += BoundingBox.W;
			}

			Point.Y += BoundingBox.H;
			Point.X = BoundingBox.X;
		}
	}


}



enum collision_layer {
	GROUND,
	FIRST_FLOOR
};

enum block_type {
	EMPTY = 0,
	PLAYER = 1,
	CREATURE = 2,
	CHEBYSHEV_WALL = 3,
	TAXICAB_WALL = 4,
	METRICLESS_WALL = 5,
	CHEBYSHEV_CRATE = 6,
	TAXICAB_CRATE = 7,
	METRICLESS_CRATE = 8,
	L_MOVER = 9,
	J_MOVER = 10
};

enum block_attributes {
	NO_ATTRIBUTE = 0,
	ACCEPTS_INPUT = 1,
	MOVABLE = 2,
	STATIONARY = 4,
	FLOATING = 8,
	ROTATABLE = 16,
	ABLE_TO_FALL = 32,
	IMMEDIATE_FOOTING_ONLY = 64,
	STICKS_TO_WALLS = 128,
	STICKS_TO_SPIKES = 256,
	LINKS_TO_PLAYER = 512,
	LINKS_TO_CRATES = 1024,
	LINKS_TO_CREATURES = 2048,
	LINKS_TO_HINGES = 4096,
	STICKS_TO_HINGES = 8192
};

typedef struct {
	u16 Type;
	u16 Attributes;
}block_properties;

enum movement_flag {
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	THREE = 4,
	FOUR = 8,
	FIVE = 16,
	SIX = 32,
	SEVEN = 64,
	EIGHT = 128
};

enum movement_direction {
	UP = 1,
	DOWN = 2,
	LEFT = 4,
	RIGHT = 8
};

/*
enum groundedness {
	FLOATING,
	STANDING
};
*/

union mechanical_state{
	u32 Flags;
	struct {
		u8 MovementFlag;
		u8 MovementState;
		u8 MovementDirection;
		u8 Groundedness;
	};

};

//TODO(ian): Indices should be signed integers instead of unsigned

typedef struct transition_state{
	r32 MoveTime;
	r32 Time;
	u32 SuperBlockID;
	u32 MovementState;
	v2 Move;
	r32 Angle;
	v2 RotationPoint;
}transition_state;




typedef struct {
	mechanical_state Input;
	mechanical_state Output;
}mechanical_rule;



//TODO(ian); make integer vectors!!


//TODO(ian): Change this; think of a smarter way to do capture the essence of a block!!!
typedef struct {
	i2 Move;
	block_properties Properties;
} block;

#define LEVELWIDTH 16
#define LEVELHEIGHT 16


typedef struct{
	block Grid[LEVELWIDTH * LEVELHEIGHT];
}level;

typedef struct {
	r32 TimeHeld;
	u32 KeyOne;
	u32 KeyTwo;
	b32 CurrentPressed;
	b32 PreviousPressed;
}key_action;

typedef struct {
	key_action Undo;
	key_action Restart;
	key_action Up;
	key_action Down;
	key_action Left;
	key_action Right;
	r32 dt;
}user_input;

/*
typedef struct {
	r2 Screen;
	texture Texture;
	prng_state PRNG;
	block *Blocks;
	v2 GridSize;
	v2 BlockSize;
	u32 PlayerIndex;
	u32 NumGround;
	u32 NumBlocks;
	u32 NumSuperBlocks;
	r64 tSine;
	u16 SoundOffset;
	transition_state Transitions[8];
}game_state;*/


#define MAX_BLOCKS 300
#define MAX_UNDOS 4100
typedef struct {
	block Grid[LEVELHEIGHT*LEVELWIDTH];
	block_properties PreviousState[MAX_UNDOS+41];
	u32 TotalStateBytes;
	u32 TotalStateEntries;
	r2 Screen;
	texture WallTextures[2];
	texture BlockTextures[2];
	texture PlayerTexture;
	prng_state PRNG;
	i2 PreviousMove;
	u32 PlayerIndex;
	b32 DiagonalMove;
	b32 ChangeBlockType;
	r32 AgainTime;
	r64 tSine;
	u16 SoundOffset;
}game_state;

typedef struct {
	v2 Hit;
	r32 LinePer;
	r32 RayPer;
}ray_variables;


inline block_properties
InitializeMetriclessWallProperties()
{
	return block_properties{ METRICLESS_WALL,STATIONARY };
}

inline block_properties
InitializeChebyshevWallProperties()
{
	return block_properties{ CHEBYSHEV_WALL,STATIONARY };
}

inline block_properties
InitializeTaxicabWallProperties()
{
	return block_properties{ TAXICAB_WALL,STATIONARY };
}

inline block_properties
InitializeCreatureProperties()
{
	return block_properties{ CREATURE,STICKS_TO_SPIKES | LINKS_TO_CREATURES | STICKS_TO_WALLS | MOVABLE };
}

inline block_properties
InitializePlayerProperties()
{
	return block_properties{ PLAYER,ACCEPTS_INPUT | LINKS_TO_CRATES | STICKS_TO_WALLS | MOVABLE | ABLE_TO_FALL | IMMEDIATE_FOOTING_ONLY};
}

inline block_properties
InitializeMetriclessCrateProperties()
{
	return block_properties{ METRICLESS_CRATE,LINKS_TO_CRATES | STICKS_TO_WALLS | STICKS_TO_HINGES | MOVABLE | ABLE_TO_FALL | IMMEDIATE_FOOTING_ONLY};
}

inline block_properties
InitializeChebyshevCrateProperties()
{
	return block_properties{ CHEBYSHEV_CRATE,LINKS_TO_CRATES | STICKS_TO_WALLS | STICKS_TO_HINGES | MOVABLE | ABLE_TO_FALL };
}

inline block_properties
InitializeTaxicabCrateProperties()
{
	return block_properties{ TAXICAB_CRATE,LINKS_TO_CRATES | STICKS_TO_WALLS | STICKS_TO_HINGES | MOVABLE | ABLE_TO_FALL };
}

inline b32
IsMoveable(block_properties Properties)
{
	b32 Result = AreBitsSet((u32)Properties.Attributes, MOVABLE);
	return Result;
}

inline b32
IsCreature(block_properties Properties)
{
	b32 Result = (Properties.Type == CREATURE);
	return Result;
}

inline b32
IsMetriclessWall(block_properties Properties)
{
	b32 Result = (Properties.Type == METRICLESS_WALL);
	return Result;
}

inline b32
IsChebyshevWall(block_properties Properties)
{
	b32 Result = (Properties.Type == CHEBYSHEV_WALL);
	return Result;
}

inline b32
IsTaxicabWall(block_properties Properties)
{
	b32 Result = (Properties.Type == TAXICAB_WALL);
	return Result;
}

inline b32
IsMetriclessCrate(block_properties Properties)
{
	b32 Result = (Properties.Type == METRICLESS_CRATE);
	return Result;
}

inline b32
IsChebyshevCrate(block_properties Properties)
{
	b32 Result = (Properties.Type == CHEBYSHEV_CRATE);
	return Result;
}

inline b32
IsTaxicabCrate(block_properties Properties)
{
	b32 Result = (Properties.Type == TAXICAB_CRATE);
	return Result;
}

inline b32
IsPlayer(block_properties Properties)
{
	b32 Result = (Properties.Type == PLAYER);
	return Result;
}



internal u32
FindEmptyTransition(transition_state *Transitions,u32 MaxTransitions)
{
	u32 Result = -1;
	for (u32 EmptyTransitionIndex = 0;
		EmptyTransitionIndex < MaxTransitions;
		++EmptyTransitionIndex)
	{
		if (Transitions[EmptyTransitionIndex].MovementState == STATIONARY)
		{
			Result = EmptyTransitionIndex;
			break;
		}
	}

	return Result;
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

internal void
AddUndo(block* Grid,block_properties* PreviousState, u32* TotalStateBytes, u32* TotalStateEntries)
{
	u32 TotalStuff = 0;
	
	for (u32 Y = 0;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (u32 X = 0;
			X < LEVELWIDTH;
			++X)
		{
			if (AreBitsSet(Grid[Y*LEVELWIDTH + X].Properties.Attributes, MOVABLE))
			{
				PreviousState[(*TotalStateBytes)++] = Grid[Y*LEVELWIDTH + X].Properties;
				PreviousState[(*TotalStateBytes)++] = block_properties{ (u16)X,(u16)Y };
				TotalStuff += 2;
			}
		}
	}
	++(*TotalStateEntries);
	PreviousState[(*TotalStateBytes)++] = block_properties{ (u16)TotalStuff,(u16)-1 };
}

internal void
UndoTurn(block *Grid, block_properties* PreviousState,u32* TotalStateBytes,u32* TotalStateEntries)
{
	for (u32 Y = 0;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (u32 X = 0;
			X < LEVELWIDTH;
			++X)
		{
			if (AreBitsSet(Grid[Y*LEVELWIDTH + X].Properties.Attributes, MOVABLE))
			{
				Grid[Y*LEVELWIDTH + X].Properties = block_properties{ 0,0 };
			}
		}
	}

	u32 TotalStuff = 0;
	for (u32 I = *TotalStateBytes - (u32)PreviousState[*TotalStateBytes - 1].Type - 1;
		PreviousState[I].Attributes != (u16)-1;
		I += 2)
	{
		TotalStuff += 2;
		Grid[PreviousState[I + 1].Attributes*LEVELWIDTH + PreviousState[I + 1].Type].Properties = PreviousState[I];
	}

	*TotalStateBytes -= TotalStuff + 1;
	--(*TotalStateEntries);

}


internal void
RestartTurn(block *Grid, block_properties* PreviousState, u32*TotalStateBytes, u32* TotalStateEntries)
{
	//AddUndo(Grid, PreviousState, TotalStateBytes, TotalStateEntries);

	for (u32 Y = 0;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (u32 X = 0;
			X < LEVELWIDTH;
			++X)
		{
			if (AreBitsSet(Grid[Y*LEVELWIDTH + X].Properties.Attributes, MOVABLE))
			{
				Grid[Y*LEVELWIDTH + X].Properties = block_properties{ 0,0 };
			}
		}
	}

	u32 I;
	for (I = 0;
		PreviousState[I].Attributes != (u16)-1;
		I += 2)
	{
		Grid[PreviousState[I + 1].Attributes*LEVELWIDTH + PreviousState[I + 1].Type].Properties = PreviousState[I];
	}

	*TotalStateBytes = 0;
	*TotalStateEntries = 0;
}


#define MAXMOVEABLES 20

internal b32
AlreadyTagged(u32* Indices, u32 NumIndices, u32 Index)
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
TagType(block* Grid, u32* Indices, u32* NumIndices, s32 X, s32 Y, u32 Type)
{
	s32 Delta = 1;
	if (Type == TAXICAB_CRATE || Type == TAXICAB_WALL)
	{
		Delta = 2;
	}
	for (s32 I = 0;
		I < 8;
		I+=Delta)
	{
		i2 Vector = CEuler(I);
		u32 Index = (u32)((Y + Vector.Y)*LEVELWIDTH + X + Vector.X);
		block SurroundingCell = Grid[Index];
		if (SurroundingCell.Properties.Type == Type)
		{
			if (!AlreadyTagged(Indices, *NumIndices, Index))
			{
				Indices[(*NumIndices)++] = Index;
				TagType(Grid, Indices, NumIndices, X + Vector.X, Y + Vector.Y, Type);
			}
		}
	}
}



internal b32
IsSticky(block* Grid, u32* Indices, u32* NumIndices, s32 X, s32 Y)
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
			s32 Index = (Y + I)*LEVELWIDTH + X + J;
			block SurroundingCell = Grid[Index];
			
			if (IsChebyshevWall(SurroundingCell.Properties))
			{
				Sticky = true;
				break;
			}
			else if (IsChebyshevCrate(SurroundingCell.Properties))
			{
				if (!AlreadyTagged(Indices, *NumIndices, Index))
				{
					Indices[(*NumIndices)++] = (u32)Index;
					if ((Sticky = IsSticky(Grid, Indices, NumIndices, X + J, Y + I)))
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

internal b32
TouchingMetriclessWall(block* Grid, u32* Indices, u32* NumIndices, s32 X, s32 Y, u32 Type = CHEBYSHEV_CRATE)
{
	b32 Touching = false;
	for (s32 I = -1;
		I < 2;
		++I)
	{
		for (s32 J = -1;
			J < 2;
			++J)
		{
			u32 Index = (u32)((Y + I)*LEVELWIDTH + X + J);
			block SurroundingCell = Grid[Index];
			if (IsMetriclessWall(SurroundingCell.Properties))
			{
				Touching = true;
				break;
			}
			if (SurroundingCell.Properties.Type == Type)
			{
				if (!AlreadyTagged(Indices, *NumIndices, Index))
				{
					Indices[(*NumIndices)++] = Index;
					if (Touching = TouchingMetriclessWall(Grid, Indices, NumIndices, X + J, Y + I, Type))
					{
						break;
					}
				}
			}
		}
		if (Touching)
		{
			break;
		}
	}

	return Touching;
}

internal b32
ChangingCrateType(block* Grid)
{
	b32 ChangesHappening = false;
	for (s32 Y = 0;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (s32 X = 0;
			X < LEVELWIDTH;
			++X)
		{
			s32 Index = Y * LEVELWIDTH + X;
			block SurroundingCell = Grid[Index];
			if (IsChebyshevCrate(SurroundingCell.Properties))
			{
				u32 Indices[30];
				u32 NumIndices = 0;
				if (!IsSticky(Grid, Indices, &NumIndices, X, Y))
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
							if (IsMetriclessWall(Grid[(Y + I)*LEVELWIDTH + X + J].Properties))
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
						Grid[Index].Properties.Type = METRICLESS_CRATE;
						Grid[Index].Properties.Attributes = SetBits(Grid[Index].Properties.Attributes, IMMEDIATE_FOOTING_ONLY);
						ChangesHappening = true;
					}
					
				}
			}
			else if(IsMetriclessCrate(SurroundingCell.Properties))
			{
				u32 Indices[30];
				u32 NumIndices = 0;
				if (IsSticky(Grid, Indices, &NumIndices, X, Y))
				{
					Grid[Index].Properties.Type = CHEBYSHEV_CRATE;
					Grid[Index].Properties.Attributes = EraseBits(Grid[Index].Properties.Attributes, IMMEDIATE_FOOTING_ONLY);
					ChangesHappening = true;
				}
			}
		}
	}
	return ChangesHappening;
}





internal b32
IsFalling(block* Grid, u32* Indices, u32* NumIndices, s32 X, s32 Y, block_properties BlockStuff, u32 RecursionDepth = 0)
{
	b32 Falling = true;

	if (AreBitsSet(BlockStuff.Attributes, ABLE_TO_FALL))
	{
		s32 PrimaryIndex = (Y - 1)*LEVELWIDTH + X;
		block_properties BlockUnderneathProperties = Grid[PrimaryIndex].Properties;
		b32 IsType = BlockUnderneathProperties.Type == BlockStuff.Type;
		if (BlockStuff.Type == METRICLESS_CRATE)
		{
			IsType = (BlockUnderneathProperties.Type == EMPTY);
		}
		if (!IsType && BlockUnderneathProperties.Attributes != 0)
		{
			if (RecursionDepth == 0 || !AreBitsSet(BlockStuff.Attributes, IMMEDIATE_FOOTING_ONLY)) return false;
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
			u32 Index = (u32)((Y + I)*LEVELWIDTH + X + J);
			block SurroundingCell = Grid[Index];
			if (!AlreadyTagged(Indices, *NumIndices, Index))
			{
				if (IsChebyshevWall(SurroundingCell.Properties) && AreBitsSet(BlockStuff.Attributes,STICKS_TO_WALLS))
				{
					return false;
				}
				else if (IsMetriclessWall(SurroundingCell.Properties) && AreBitsSet(BlockStuff.Attributes, STICKS_TO_SPIKES))
				{
					return false;
				}
				else if (IsChebyshevCrate(SurroundingCell.Properties) && AreBitsSet(BlockStuff.Attributes, LINKS_TO_CRATES))
				{
					Indices[(*NumIndices)++] = Index;
					if (!IsFalling(Grid, Indices, NumIndices, X + J, Y + I, BlockStuff, RecursionDepth + 1))
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




internal b32
AreAllBlocksMoving(game_state* GameState, u32* Indices, u32* NumIndices, u32 X, u32 Y)
{
	b32 Moving = true;
	for (u32 I = 0;
		I < 3;
		++I)
	{
		for (u32 J = 0;
			J < 3;
			++J)
		{

			u32 Index = (Y + I - 1)*LEVELWIDTH + X + J - 1;
			if (IsChebyshevCrate(GameState->Grid[Index].Properties))
			{
				b32 AlreadyFound = false;
				for (u32 K = 0;
					K < *NumIndices;
					++K)
				{
					if (Index == Indices[K])
					{
						AlreadyFound = true;
						break;
					}
				}
				if (!AlreadyFound)
				{
					Indices[(*NumIndices)++] = Index;
					if ((LengthSq(GameState->Grid[Index].Move) != 0.0f))
					{
						if (!AreAllBlocksMoving(GameState, Indices, NumIndices, X + J - 1, Y + I - 1))
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	return Moving;
}

internal void
ApplyMoveToBlocks(game_state* GameState, u32* Indices, u32* NumIndices, i2 Move, s32 X, s32 Y)
{
	for (s32 I = -1;
		I < 2;
		++I)
	{
		for (s32 J = -1;
			J < 2;
			++J)
		{

			u32 Index = (u32)((Y + I)*LEVELWIDTH + X + J);
			if (IsChebyshevCrate(GameState->Grid[Index].Properties))
			{
				if (!AlreadyTagged(Indices, *NumIndices, Index))
				{
					Indices[(*NumIndices)++] = Index;
					GameState->Grid[Index].Move = Move;
					ApplyMoveToBlocks(GameState, Indices, NumIndices, Move, X + J, Y + I);
				}
			}
		}
	}
}


internal b32
ImplementMovingRules(game_state* GameState, i2 Move)
{

	for (u32 Y = 1;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH;
			++X)
		{
			GameState->Grid[Y*LEVELWIDTH + X].Move = i2{ 0,0 };
		}
	}

	b32 MoveImplemented = false;

	// #1 1. Apply direction to player
	GameState->Grid[GameState->PlayerIndex].Move = Move;
	i2 PlayerPos;
	PlayerPos.X = GameState->PlayerIndex%LEVELWIDTH;
	PlayerPos.Y = GameState->PlayerIndex / LEVELWIDTH;


	u32 AdjacentIndex = (PlayerPos.Y + Move.Y) * LEVELWIDTH + (Move.X + PlayerPos.X);
	if (IsChebyshevWall(GameState->Grid[AdjacentIndex].Properties) || IsMetriclessWall(GameState->Grid[AdjacentIndex].Properties)) //#2 Player against Wall/spike
	{
		GameState->Grid[GameState->PlayerIndex].Move = i2{ 0,0 };
	}
	else if (GameState->Grid[AdjacentIndex].Properties.Type == 0) // #4 Player in empty square
	{
		u32 Indices[30];
		u32 NumIndices = 0;

		if (!IsSticky(GameState->Grid, Indices, &NumIndices, (AdjacentIndex%LEVELWIDTH), (AdjacentIndex / LEVELWIDTH)))
		{
			GameState->Grid[GameState->PlayerIndex].Move = i2{ 0,0 };
		}
	}
	else if (IsMetriclessCrate(GameState->Grid[AdjacentIndex].Properties) || IsChebyshevCrate(GameState->Grid[AdjacentIndex].Properties)) // #5  player pushes block
	{
		GameState->Grid[AdjacentIndex].Move = Move;
		
		if (IsChebyshevCrate(GameState->Grid[AdjacentIndex].Properties))
		{
			u32 Indices[30];
			u32 NumIndices = 0;
			s32 X = (s32)AdjacentIndex % LEVELWIDTH;
			s32 Y = (s32)AdjacentIndex / LEVELWIDTH;
			ApplyMoveToBlocks(GameState, Indices, &NumIndices, Move, X, Y); // #6 Block 'pushes' blocks
		}


		b32 FoundPattern;
		// #7 block against block
		do {
			FoundPattern = false;
			for (s32 Y = 1;
				Y < LEVELHEIGHT - 1;
				++Y)
			{
				for (s32 X = 1;
					X < LEVELWIDTH - 1;
					++X)
				{
					block Cell = GameState->Grid[Y*LEVELWIDTH + X];
					if ((IsChebyshevCrate(Cell.Properties) || IsMetriclessCrate(Cell.Properties)) && TLength(Cell.Move) > 0)
					{
						s32 NearbyIndex = (Y+Cell.Move.Y) * LEVELWIDTH + Cell.Move.X + X;
						if (TLength(GameState->Grid[NearbyIndex].Move) == 0)
						{
							if (IsChebyshevCrate(GameState->Grid[NearbyIndex].Properties))
							{
								u32 Indices[30];
								u32 NumIndices = 0;
								GameState->Grid[NearbyIndex].Move = Cell.Move;
								ApplyMoveToBlocks(GameState, Indices, &NumIndices, Cell.Move, X+Cell.Move.X, Y+Cell.Move.Y);
								FoundPattern = true;
							}
							else if (IsMetriclessCrate(GameState->Grid[NearbyIndex].Properties))
							{
								GameState->Grid[NearbyIndex].Move = Cell.Move;
								FoundPattern = true;
							}
						}
					}
				}
			}
		} while (FoundPattern);





		// #7 block against 'barrier'
		do {
			FoundPattern = false;
			for (s32 Y = 1;
				Y < LEVELHEIGHT - 1;
				++Y)
			{
				for (s32 X = 1;
					X < LEVELWIDTH - 1;
					++X)
				{
					block Cell = GameState->Grid[Y*LEVELWIDTH + X];
					if ((IsChebyshevCrate(Cell.Properties)) && LengthSq(Cell.Move) > 0)
					{
						s32 NearbyIndex = (Y + Cell.Move.Y) * LEVELWIDTH + Cell.Move.X + X;
						if (IsChebyshevWall(GameState->Grid[NearbyIndex].Properties) || IsMetriclessWall(GameState->Grid[NearbyIndex].Properties)
							|| IsPlayer(GameState->Grid[NearbyIndex].Properties) || (IsChebyshevCrate(GameState->Grid[NearbyIndex].Properties) && LengthSq(GameState->Grid[NearbyIndex].Move) == 0)
							|| (IsMetriclessCrate(GameState->Grid[NearbyIndex].Properties) && LengthSq(GameState->Grid[NearbyIndex].Move) == 0))
						{
							u32 Indices[30];
							u32 NumIndices = 0;
							GameState->Grid[Y*LEVELWIDTH + X].Move = i2{ 0,0 };
							s32 x = AdjacentIndex % LEVELWIDTH;
							s32 y = AdjacentIndex / LEVELWIDTH;
							ApplyMoveToBlocks(GameState, Indices, &NumIndices, i2{ 0,0 }, x,y);
							FoundPattern = true;
						}
					}
					else if ((IsMetriclessCrate(Cell.Properties)) && LengthSq(Cell.Move) > 0)
					{
						s32 NearbyIndex = (Y + Cell.Move.Y) * LEVELWIDTH + Cell.Move.X + X;
						if (IsChebyshevWall(GameState->Grid[NearbyIndex].Properties) || IsMetriclessWall(GameState->Grid[NearbyIndex].Properties)
							|| IsPlayer(GameState->Grid[NearbyIndex].Properties) || (IsChebyshevCrate(GameState->Grid[NearbyIndex].Properties) && LengthSq(GameState->Grid[NearbyIndex].Move) == 0)
							|| (IsMetriclessCrate(GameState->Grid[NearbyIndex].Properties) && LengthSq(GameState->Grid[NearbyIndex].Move) == 0))
						{

							GameState->Grid[Y*LEVELWIDTH + X].Move = i2{ 0,0 };
							FoundPattern = true;
						}
					}
					
				}
			}
		} while (FoundPattern);



		// #9 Player against stationary block
		if ((IsChebyshevCrate(GameState->Grid[AdjacentIndex].Properties) || IsMetriclessCrate(GameState->Grid[AdjacentIndex].Properties))
			&& LengthSq(GameState->Grid[AdjacentIndex].Move) == 0)
		{
			GameState->Grid[GameState->PlayerIndex].Move = i2{ 0,0 };
		}
	}


	if (LengthSq(GameState->Grid[GameState->PlayerIndex].Move) > 0)
	{
		GameState->PreviousMove = Move;
		MoveImplemented = true;
		s32 Angle = GetAngle(Move);
		if (Angle <= 1)
		{
			for (u32 X = LEVELWIDTH - 2;
				X >= 1;
				--X)
			{
				for (u32 Y = LEVELWIDTH - 2;
					Y >= 1;
					--Y)
				{
					u32 CellIndex = Y * LEVELWIDTH + X;
					block Cell = GameState->Grid[CellIndex];
					if (LengthSq(GameState->Grid[CellIndex].Move) > 0)
					{
						u32 NewIndex = (Y + (u32)Move.Y)*LEVELWIDTH + X + (u32)Move.X;
						GameState->Grid[NewIndex] = Cell;
						GameState->Grid[CellIndex] = block{ i2{0,0},block_properties{0,0} };
						if (IsPlayer(Cell.Properties))
						{
							GameState->PlayerIndex = NewIndex;
						}
					}
				}
			}
		}
		else if (Angle <= 3)
		{
			for (u32 Y = LEVELWIDTH - 2;
				Y >= 1;
				--Y)
			{
				for (u32 X = 0;
					X < LEVELWIDTH;
					++X)
				{
					u32 CellIndex = Y * LEVELWIDTH + X;
					block Cell = GameState->Grid[CellIndex];
					if (LengthSq(GameState->Grid[CellIndex].Move) > 0)
					{
						u32 NewIndex = (Y + (u32)Move.Y)*LEVELWIDTH + X + (u32)Move.X;
						GameState->Grid[NewIndex] = Cell;
						GameState->Grid[CellIndex] = block{ i2{ 0,0 },block_properties{ 0,0 } };
						if (IsPlayer(Cell.Properties))
						{
							GameState->PlayerIndex = NewIndex;
						}
					}
				}
			}
		}
		else if (Angle <= 5)
		{
			for (u32 X = 0;
				X < LEVELWIDTH;
				++X)
			{
				for (u32 Y = LEVELWIDTH - 2;
					Y >= 1;
					--Y)
				{
					u32 CellIndex = Y * LEVELWIDTH + X;
					block Cell = GameState->Grid[CellIndex];
					if (LengthSq(GameState->Grid[CellIndex].Move) > 0)
					{
						u32 NewIndex = (Y + (u32)Move.Y)*LEVELWIDTH + X + (u32)Move.X;
						GameState->Grid[NewIndex] = Cell;
						GameState->Grid[CellIndex] = block{ i2{ 0,0 },block_properties{ 0,0 } };
						if (IsPlayer(Cell.Properties))
						{
							GameState->PlayerIndex = NewIndex;
						}
					}
				}
			}
		}
		else if (Angle <= 7)
		{
			for (u32 Y = 0;
				Y < LEVELWIDTH;
				++Y)
			{
				for (u32 X = 0;
					X < LEVELWIDTH;
					++X)
				{
					u32 CellIndex = Y * LEVELWIDTH + X;
					block Cell = GameState->Grid[CellIndex];
					if (LengthSq(GameState->Grid[CellIndex].Move) > 0)
					{
						u32 NewIndex = (Y + (u32)Move.Y)*LEVELWIDTH + X + (u32)Move.X;
						GameState->Grid[NewIndex] = Cell;
						GameState->Grid[CellIndex] = block{ i2{ 0,0 },block_properties{ 0,0 } };
						if (IsPlayer(Cell.Properties))
						{
							GameState->PlayerIndex = NewIndex;
						}
					}
				}
			}
		}

	}


	return MoveImplemented;
}



internal void
EnactGravity(game_state* GameState)
{
	u32 BlockIndices[30];
	u32 Num = 0;
	block Blocks[30];
	u32 TempIndices[30];
	u32 NumIndices = 0;
	b32 FoundPattern = false;
	for (s32 Y = 0;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (s32 X = 1;
			X < LEVELWIDTH - 1;
			++X)
		{
			block Cell = GameState->Grid[Y*LEVELWIDTH + X];
			if (AreBitsSet(Cell.Properties.Attributes,ABLE_TO_FALL))
			{
				NumIndices = 0;
				if (IsFalling(GameState->Grid, TempIndices, &NumIndices, X, Y, Cell.Properties))
				{
					BlockIndices[Num] = (u32)((Y - 1) * LEVELWIDTH + X);
					Blocks[Num++] = Cell;
					FoundPattern = true;
				}
				else
				{
					BlockIndices[Num] = (u32)(Y* LEVELWIDTH + X);
					Blocks[Num++] = Cell;
				}
			}
		}
	}

	for (s32 Y = 0;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (s32 X = 1;
			X < LEVELWIDTH - 1;
			++X)
		{
			block Cell = GameState->Grid[Y*LEVELWIDTH + X];
			if (AreBitsSet(Cell.Properties.Attributes, ABLE_TO_FALL))
			{
				GameState->Grid[Y*LEVELWIDTH + X] = block{ i2{ 0,0 },block_properties{ 0,0 } };
			}
		}
	}

	
	for (u32 I = 0;
		I < Num;
		++I)
	{
		GameState->Grid[BlockIndices[I]] = Blocks[I];
	}
}

internal void
ExecuteTurn(game_state* GameState, u32 Pressed, u32 Held)
{

	GameState->DiagonalMove = false;

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
		else if (AreBitsSet(Pressed, LEFT)) Move = i2{ -1,0};
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


	if (GameState->TotalStateBytes < MAX_UNDOS)
	{
		AddUndo(GameState->Grid, GameState->PreviousState, &GameState->TotalStateBytes, &GameState->TotalStateEntries);
	}
	else
	{
		printf("\nOut of Undos! There are %d entries.", GameState->TotalStateEntries);
	}


	b32 AddingUndo = ImplementMovingRules(GameState, Move);

	if (!AddingUndo && NumPressed == 1 && NumHeld == 1)
	{
		if (AreBitsSet(Pressed, UP)) Move = Move + I2( 0,1 );
		else if (AreBitsSet(Pressed, DOWN)) Move = Move + I2( 0,-1 );
		else if (AreBitsSet(Pressed, LEFT)) Move = Move + I2(-1, 0);
		else if (AreBitsSet(Pressed, RIGHT)) Move = Move + I2( 1,0 );

		AddingUndo = ImplementMovingRules(GameState, Move);
		GameState->DiagonalMove = AddingUndo;
	}

	
	if (!AddingUndo && GameState->TotalStateEntries > 0)
	{
		--GameState->TotalStateEntries;
		GameState->TotalStateBytes -= GameState->PreviousState[GameState->TotalStateBytes - 1].Type + 1;
	}
}

internal void
GameUpdateAndRender(game_state *GameState, user_input *Input, texture *Window,
	u8 *SoundData, s32 BytesToWrite, u16 Samples)
{

	i2 Move = { 0 };
	r32 AgainTime = 0.2f;
	u32 Pressed = 0, Held = 0;
	if (!Input->Up.PreviousPressed && Input->Up.CurrentPressed)
	{
		Pressed |= UP;
	}

	if (!Input->Down.PreviousPressed && Input->Down.CurrentPressed)
	{
		Pressed |= DOWN;
	}

	if (!Input->Left.PreviousPressed && Input->Left.CurrentPressed)
	{
		Pressed |= LEFT;
	}

	if (!Input->Right.PreviousPressed && Input->Right.CurrentPressed)
	{
		Pressed |= RIGHT;
	}



	if (Pressed)
	{
		if (Input->Up.PreviousPressed && Input->Up.CurrentPressed)
		{
			Held |= UP;
		}


		if (Input->Down.PreviousPressed && Input->Down.CurrentPressed)
		{
			Held |= DOWN;
		}

		if (Input->Left.PreviousPressed && Input->Left.CurrentPressed)
		{
			Held |= LEFT;
		}

		if (Input->Right.PreviousPressed && Input->Right.CurrentPressed)
		{
			Held |= RIGHT;
		}
	}
	else
	{

		if (Input->Up.PreviousPressed && Input->Up.CurrentPressed)
		{
			if (Input->Up.TimeHeld >= AgainTime)
			{
				Held |= UP;
				Input->Up.TimeHeld -= AgainTime;
			}
		}


		if (Input->Down.PreviousPressed && Input->Down.CurrentPressed)
		{
			if (Input->Down.TimeHeld >= AgainTime)
			{
				Held |= DOWN;
				Input->Down.TimeHeld -= AgainTime;
			}
		}

		if (Input->Left.PreviousPressed && Input->Left.CurrentPressed)
		{
			if (Input->Left.TimeHeld >= AgainTime)
			{
				Held |= LEFT;
				Input->Left.TimeHeld -= AgainTime;
			}
		}

		if (Input->Right.PreviousPressed && Input->Right.CurrentPressed)
		{
			if (Input->Right.TimeHeld >= AgainTime)
			{
				Held |= RIGHT;
				Input->Right.TimeHeld -= AgainTime;
			}
		}
	}



	if (GameState->TotalStateEntries > 0)
	{
		if (!Input->Undo.PreviousPressed && Input->Undo.CurrentPressed)
		{
			UndoTurn(GameState->Grid, GameState->PreviousState, &GameState->TotalStateBytes, &GameState->TotalStateEntries);
		}
		else if (Input->Undo.PreviousPressed && Input->Undo.CurrentPressed)
		{
			if (Input->Undo.TimeHeld >= AgainTime)
			{
				UndoTurn(GameState->Grid, GameState->PreviousState, &GameState->TotalStateBytes, &GameState->TotalStateEntries);
			}
		}

		if (!Input->Restart.PreviousPressed && Input->Restart.CurrentPressed)
		{
			RestartTurn(GameState->Grid, GameState->PreviousState, &GameState->TotalStateBytes, &GameState->TotalStateEntries);
		}
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


	
	//GameState->PlayerIndex = -1;
	b32 Falling = false;
	{
		u32 Indices[30];
		u32 NumIndices = 0;
		
		for (u32 Y = 1;
			Y < LEVELHEIGHT-1;
			++Y)
		{
			for (u32 X = 1;
				X < LEVELWIDTH-1;
				++X)
			{
				block Cell = GameState->Grid[Y*LEVELWIDTH + X];
				if (AreBitsSet(Cell.Properties.Attributes,ABLE_TO_FALL))
				{
					NumIndices = 0;
					if (IsFalling(GameState->Grid, Indices, &NumIndices, (s32)X, (s32)Y, GameState->Grid[Y*LEVELWIDTH + X].Properties))
					{
						Falling = true;
						break;
					}
				}
			}
			if (Falling)
			{
				break;
			}
		}
	}


	for (u32 Y = 1;
		Y < LEVELHEIGHT - 1;
		++Y)
	{
		b32 FoundPlayer = false;
		for (u32 X = 1;
			X < LEVELWIDTH - 1;
			++X)
		{
			block Cell = GameState->Grid[Y*LEVELWIDTH + X];
			if (IsPlayer(Cell.Properties))
			{
				GameState->PlayerIndex = Y * LEVELWIDTH + X;
				FoundPlayer = true;
				break;
			}
		}
		if (FoundPlayer)
		{
			break;
		}
	}

	GameState->ChangeBlockType = ChangingCrateType(GameState->Grid);




	GameState->AgainTime += Input->dt;
	if (!GameState->ChangeBlockType)
	{
		if (!Falling)
		{
			if (CLength(Move) != 0)
			{
				if (!GameState->DiagonalMove)
				{
					ExecuteTurn(GameState, Pressed, Held);
					GameState->AgainTime = 0.0f;
				}
				else
				{
					if (GameState->AgainTime >= AgainTime*0.3f)
					{
						GameState->AgainTime = 0.0f;
						GameState->DiagonalMove = false;
					}
				}
			}
		}
		else
		{
			if (GameState->AgainTime >= AgainTime)
			{
				GameState->AgainTime -= AgainTime;
				EnactGravity(GameState);
				for (u32 I = 0;
					I < LEVELWIDTH*LEVELHEIGHT;
					++I)
				{
					if (GameState->Grid[I].Properties.Attributes == GameState->Grid[I].Properties.Type && GameState->Grid[I].Properties.Type != 0)
					{
						int u = 9;
					}
				}
			}
		}
	}


	



	v2 PlayerCenter = V2((s32)GameState->PlayerIndex%LEVELWIDTH, LEVELHEIGHT - 1 - (s32)GameState->PlayerIndex / LEVELHEIGHT) + V2(0.5f,0.5f);
	GameState->Screen.P = (0.9f*GameState->Screen.P) + (0.1f*(PlayerCenter-(0.5f*GameState->Screen.Size)));


	i2 BackgroundPos = I2(Hadamard(GameState->Screen.P, v2{ 16.0F,16.0F }));


	for (s32 Y = 0;
		Y < Window->Height;
		++Y)
	{
		for (s32 X = 0;
			X < Window->Width;
			++X)
		{
			s32 Value = ((Y+BackgroundPos.Y)*Window->Width+X+BackgroundPos.X) & 0x000000ff;
			s32 Color = (Value << 16) | (Value << 8) | (Value << 0);
			Window->Texels[Y*Window->Width + X] = (u32)Color;
		}
	}
	


	for (s32 Y = LEVELHEIGHT-1;
		Y >= 0;
		--Y)
	{
		for (s32 X = 0;
			X < LEVELWIDTH;
			++X)
		{
			block_properties Field = GameState->Grid[Y*LEVELWIDTH + X].Properties;
			if (IsChebyshevWall(Field))
			{
				
				DrawRect(*Window, GameState->WallTextures[0],GameState->Screen, r2{ v2{(r32)X,(r32)(LEVELHEIGHT-Y-1)},v2{1.0f,1.0f} });
			}
			else if (IsPlayer(Field))
			{
				r2 Box = r2{ v2{ (r32)X,(r32)(LEVELHEIGHT - Y - 1) },v2{ 1.0f,1.0f } };
				s32 Angle = GetAngle(GameState->PreviousMove);
				DrawChebyshevBox(*Window, GameState->PlayerTexture, GameState->Screen, RectCenter(Box),Box, (r32)Angle, 0);
			}
			else if (IsChebyshevCrate(Field))
			{
				DrawRect(*Window, GameState->BlockTextures[0], GameState->Screen, r2{ v2{ (r32)X,(r32)(LEVELHEIGHT - Y - 1) },v2{ 1.0f,1.0f } });
			}
			else if (IsMetriclessWall(Field))
			{
				DrawRect(*Window, GameState->WallTextures[1],GameState->Screen, r2{ v2{ (r32)X,(r32)(LEVELHEIGHT - Y - 1) },v2{ 1.0f,1.0f } });
			}
			else if (IsCreature(Field))
			{
				DrawRect(*Window, GameState->Screen, r2{ v2{ (r32)X,(r32)(LEVELHEIGHT - Y - 1) },v2{ 1.0f,1.0f } }, v4{ 0.3f,0.9f,0.645f,1.0f });
			}
			else if (IsMetriclessCrate(Field))
			{
				DrawRect(*Window, GameState->BlockTextures[1],GameState->Screen, r2{ v2{ (r32)X,(r32)(LEVELHEIGHT - Y - 1) },v2{ 1.0f,1.0f } });
			}
			else if (Field.Attributes == 0 && Field.Type == 0)
			{

			}
			else
			{
				DrawRect(*Window, GameState->Screen, r2{ v2{ (r32)X,(r32)(LEVELHEIGHT - Y - 1) },v2{ 1.0f,1.0f } }, v4{ 0.1f,0.1f,0.545f,1.0f });
			}
		}
	}

	/*
		u32 Indices[30];
		u32 NumIndices = 0;
		i2 PlayerPos;
		PlayerPos.X = GameState->PlayerIndex%LEVELWIDTH;
		PlayerPos.Y = GameState->PlayerIndex / LEVELWIDTH;
		if (IsFalling(GameState->Grid,Indices,&NumIndices,PlayerPos.X,PlayerPos.Y,GameState->Grid[GameState->PlayerIndex].Properties))
		{
			DrawRect(*Window, GameState->Screen, r2{ 1.0f,0.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
		}
		else
		{
			DrawRect(*Window, GameState->Screen, r2{ 1.0f,0.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
		}
	}
	*/


	/**
	if (!NoFall)
	{
		DrawRect(*Window, GameState->Screen, r2{ 1.0f,0.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 1.0f,0.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	v2 Point = v2{ 0.0f,0.0f };
	for (u32 I = 0;
		I < GameState->TotalStateEntries;
		++I)
	{
		r32 C = Clamp(0.0f, (r32)(I/10), 1.0f);
		DrawRect(*Window, GameState->Screen, r2{ Point.X,Point.Y,0.25f,0.25f }, v4{ C,C,C,1.0f });

		if (Intersects(GameState->Screen, r2{ Point.X,Point.Y,0.25f,0.25f }))
		{
			Point.X += 0.25f;
		}
		else
		{
			Point.X = 0.0f;
			Point.Y += 0.25;
		}
	}
	*/


	/*
	if (Input->Up.CurrentPressed)
	{
		DrawRect(*Window, GameState->Screen, r2{ 1.0f,0.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 1.0f,0.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (Input->Down.CurrentPressed)
	{
		DrawRect(*Window, GameState->Screen, r2{ 1.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 1.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (Input->Left.CurrentPressed)
	{
		DrawRect(*Window, GameState->Screen, r2{ 0.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 0.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (Input->Right.CurrentPressed)
	{
		DrawRect(*Window, GameState->Screen, r2{ 2.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 2.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (AreBitsSet(Pressed, UP))
	{
		DrawRect(*Window, GameState->Screen, r2{ 6.0f,0.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 6.0f,0.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}
	
	if (AreBitsSet(Pressed, DOWN))
	{
		DrawRect(*Window, GameState->Screen, r2{ 6.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 6.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (AreBitsSet(Pressed, LEFT))
	{
		DrawRect(*Window, GameState->Screen, r2{ 5.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 5.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}


	if (AreBitsSet(Pressed, RIGHT))
	{
		DrawRect(*Window, GameState->Screen, r2{ 7.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 7.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (AreBitsSet(Held, UP))
	{
		DrawRect(*Window, GameState->Screen, r2{ 12.0f,0.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 12.0f,0.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (AreBitsSet(Held, DOWN))
	{
		DrawRect(*Window, GameState->Screen, r2{ 12.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 12.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}

	if (AreBitsSet(Held, LEFT))
	{
		DrawRect(*Window, GameState->Screen, r2{ 11.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 11.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}


	if (AreBitsSet(Held, RIGHT))
	{
		DrawRect(*Window, GameState->Screen, r2{ 13.0f,1.0f,1.0f,1.0f }, v4{ 0.0f,1.0f,0.0f,1.0f });
	}
	else
	{
		DrawRect(*Window, GameState->Screen, r2{ 13.0f,1.0f,1.0f,1.0f }, v4{ 1.0f,0.0f,0.0f,1.0f });
	}
	*/



	if (GameState->SoundOffset > 30000)
	{
		GameState->SoundOffset = 30000;
	}
	if (GameState->SoundOffset < 1)
	{
		GameState->SoundOffset = 1;
	}

	r64 Volume = 0.0;
	r64 dt = ((r64)GameState->SoundOffset) / ((r64)Samples);
	if (BytesToWrite > 0)
	{
		for (s32 SoundIndex = 0;
			SoundIndex < BytesToWrite;
			++SoundIndex)
		{
			r64 Value = (Sine(GameState->tSine) + 1.0)*Volume;
			SoundData[SoundIndex] = ((u8)Value);
			GameState->tSine += dt;
		}
	}
}


int
main(int argc, char* argv[])
{

	game_state GameState = {};


	texture WindowTexture;
	WindowTexture.Width = 512;
	WindowTexture.Height = 512;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

	SDL_Window *Window = SDL_CreateWindow("Rooms", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WindowTexture.Width, WindowTexture.Height, 0);


	SDL_Surface *Surface = SDL_GetWindowSurface(Window);

	u32 Format = Surface->format->format;

	printf("The Pixel Format is %s\n", SDL_GetPixelFormatName(Surface->format->format));
	printf("Red mask is %x\n", Surface->format->Rmask);
	printf("Green mask is %x\n", Surface->format->Gmask);
	printf("Blue mask is %x\n", Surface->format->Bmask);
	printf("Alpha mask is %x\n", Surface->format->Amask);

	//Pixel Mask is (in hex) XX RR GG BB



	SDL_AudioSpec DesiredAudio = {}, ObtainedAudio;
	DesiredAudio.freq = 48000;
	DesiredAudio.format = AUDIO_U8;
	DesiredAudio.channels = 1;
	DesiredAudio.samples = 4096;
	DesiredAudio.callback = 0;

	SDL_AudioDeviceID AudioDeviceID = SDL_OpenAudioDevice(0, 0, &DesiredAudio,
		&ObtainedAudio, SDL_AUDIO_ALLOW_ANY_CHANGE);


	if (DesiredAudio.format != ObtainedAudio.format) {
		printf("Audio not in desired format!!!\n");
		if (SDL_AUDIO_ISSIGNED(ObtainedAudio.format))
		{
			printf("Audio format is signed\n");
		}
		if (SDL_AUDIO_ISINT(ObtainedAudio.format))
		{
			printf("Audio format is an int\n");
		}
		if (SDL_AUDIO_MASK_BITSIZE & ObtainedAudio.format)
		{
			printf("Audio format is %d long\n", (int)(SDL_AUDIO_MASK_BITSIZE & ObtainedAudio.format));
		}
		return 5;
	}

	
	{
		GameState.Screen = R2(v2{ 0.0f,0.0f }, v2{ (r32)LEVELWIDTH,(r32)LEVELHEIGHT });
		GameState.Screen.Size = GameState.Screen.Size * 2.0f;  
		GameState.AgainTime = 0.0f;
		Seed(&GameState.PRNG, 100);

		GameState.BlockTextures[0].Width = 64;
		GameState.BlockTextures[0].Height = 64;
		GameState.BlockTextures[0].Texels = (u32*)AllocateChunk(GameState.BlockTextures[0].Width*GameState.BlockTextures[0].Height * sizeof(u32));
		GameState.BlockTextures[1].Width = 64;
		GameState.BlockTextures[1].Height = 64;
		GameState.BlockTextures[1].Texels = (u32*)AllocateChunk(GameState.BlockTextures[1].Width*GameState.BlockTextures[1].Height * sizeof(u32));
		GameState.WallTextures[0].Width = 64;
		GameState.WallTextures[0].Height = 64;
		GameState.WallTextures[0].Texels = (u32*)AllocateChunk(GameState.BlockTextures[0].Width*GameState.BlockTextures[0].Height * sizeof(u32));
		GameState.WallTextures[1].Width = 64;
		GameState.WallTextures[1].Height = 64;
		GameState.WallTextures[1].Texels = (u32*)AllocateChunk(GameState.BlockTextures[1].Width*GameState.BlockTextures[1].Height * sizeof(u32));
		
		for (s32 y = -32;
			y < (s32)GameState.BlockTextures[0].Height/2;
			++y)
		{
			for (s32 x = -32;
				x < (s32)GameState.BlockTextures[0].Width/2;
				++x)
			{
				s32 r, g, b;
				s32 value = Max(Abs(x), Abs(y));
				if (value > 6 && value < 26)
				{
					r = 0;
					g = 0;
					b = 0;
				}
				else
				{
					r = 255;
					g = 255;
					b = 255;
				}


				GameState.WallTextures[0].Texels[(y+32)*(s32)GameState.BlockTextures[0].Width + x + 32] = (u32)((r << 16) | (g << 8) | b);


				r = (value * 255 * 2) / GameState.BlockTextures[1].Width; 
				g = b = r;


				GameState.WallTextures[1].Texels[(y + 32)*(s32)GameState.BlockTextures[0].Width + x + 32] = (u32)((r << 16) | (g << 8) | b);


				if(((value)&8) == 0)
				{
					r = 0;
					g = 0;
					b = 0;
				}
				else
				{
					r = 255;
					g = 255;
					b = 255;
				}


				GameState.BlockTextures[0].Texels[(y + 32)*(s32)GameState.BlockTextures[0].Width + x + 32] = (u32)((r << 16) | (g << 8) | b);


				r = g = b = 128;


				GameState.BlockTextures[1].Texels[(y + 32)*(s32)GameState.BlockTextures[0].Width + x + 32] = (u32)((r << 16) | (g << 8) | b);
			}
		}

		GameState.PlayerTexture.Width = 64;
		GameState.PlayerTexture.Height = 64;
		GameState.PlayerTexture.Texels = (u32*)AllocateChunk(GameState.BlockTextures[0].Width*GameState.BlockTextures[0].Height * sizeof(u32));

		v2 Center = v2{ (r32)GameState.BlockTextures[0].Width * -0.5f,(r32)GameState.BlockTextures[0].Height * 0.5f };
		v2 Point = Center;
		v2 Triangle[3];
		Triangle[0] = V2( 1.0f,0.0f ) * (r32)GameState.PlayerTexture.Width * 0.3f;
		Triangle[1] = V2(Cosine(TAU32 / 3.0f), Sine(TAU32/3.0f)) * (r32)GameState.PlayerTexture.Width * 0.3f;
		Triangle[2] = V2(Cosine(2.0f * TAU32 / 3.0f), Sine(2.0f * TAU32 / 3.0f)) * (r32)GameState.PlayerTexture.Width * 0.3f;

		r32 Determinant = (Triangle[1].Y - Triangle[2].Y) * (Triangle[0].X - Triangle[2].X) + (Triangle[2].X - Triangle[1].X) * (Triangle[0].Y - Triangle[2].Y);

		for (u32 y = 0;
			y < GameState.PlayerTexture.Height;
			++y)
		{
			for (u32 x = 0;
				x < GameState.PlayerTexture.Width;
				++x)
			{
				u32 r, g, b;
				r32 bary[3];
				bary[0] = (Triangle[1].Y - Triangle[2].Y) * (Point.X - Triangle[2].X) + (Triangle[2].X - Triangle[1].X) * (Point.Y - Triangle[2].Y);
				bary[0] /= Determinant;
				bary[1] = (Triangle[2].Y - Triangle[0].Y) * (Point.X - Triangle[2].X) + (Triangle[0].X - Triangle[2].X) * (Point.Y - Triangle[2].Y);
				bary[1] /= Determinant;
				bary[2] = 1.0f - bary[0] - bary[1];
				
				b32 InsideTriangle = true;
				for (u32 I = 0;
					I < 3;
					++I)
				{
					if (bary[I] < 0.0f)
					{
						InsideTriangle = false;
						break;
					}
				}

				if (InsideTriangle)
				{
					r = 255;
					g = 255;
					b = 255;
				}
				else
				{
					r = 0;
					g = 0;
					b = 0;
				}

				GameState.PlayerTexture.Texels[y*GameState.PlayerTexture.Width + x] = (r << 16) | (g << 8) | b;

				Point.X += 1.0f;
			}

			Point.X = Center.X;
			Point.Y -= 1.0f;
		}


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
		//Number of puzzles so far: ~20

		//NOTE(ian): Beginning levels ~9 levels


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
			"s..............s"
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
			"s...b.xb.......s"
			"sxxx..xxx......s"
			"s..xb.x........s"
			"sp......x......s"
			"sxxxxxxxx......s"
			"ssssssssssssssss";

		/*
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s........x.....s"
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
			"s.xxxxx....xxxxs"
			"s.xx...........s"
			"s.x............s"
			"s.x............s"
			"s.p.b..........s"
			"sxxxxxxs.......s"
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
		
		/*
		//TODO(ian): this is much better! Keep/iterate
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..........b...s"
			"s..........xb..s"
			"s..........p...s"
			"s.......xxxxxxxs"
			"s.......xxxxxxxs"
			"s.........xxxxxs"
			"s.........xxxxxs"
			"s...........xxxs"
			"s...........xxxs"
			"s..............s"
			"sxxxx..........s"
			"s..............s"
			"s..............s"
			"ssssssssssssssss";

		*/
		/*
		//TODO(ian): need to find out whether the diagonal control scheme is simple enough to be found out by accident!!
		//NOTE(ian): this is pretty good. Keep/iterate upon this concept!!!
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"sp..b.b.b......s"
			"sxxxxxxxx......s"
			"sxxxxxxxb......s"
			"sxxxxxbbx......s"
			"sxxxxxxxx......s"
			"sxxxxx.........s"
			"sxxxx..........s"
			"sxxx...........s"
			"sxx............s"
			"sx.............s"
			"s..............s"
			"s..........xxxxs"
			"ssssssssssssssss";


		//NOTE(ian): Diagonal Levels ~9 levels


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

		/*

		//NOTE(ian): keep/iterate - this is pretty cool

		const char* Level =
			"ssssssssssssssss"
			"s.xxxxxxxxxxxxxs"
			"ss.xxxxxxxxxxxxs"
			"s...xxxxxxxxxxxs"
			"s....xxxxxxxxxxs"
			"sxxxx..........s"
			"sxxxxx.........s"
			"sxxxxxx........s"
			"sxxxxxxx.......s"
			"sxxxxxxxx......s"
			"s..............s"
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


		//NOTE(ian): Metricless Block levels ~3

		*/
		//NOTE(ian): much better!
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s.x............s"
			"s..............s"
			"s..............s"
			"s.........s....s"
			"s........x.....s"
			"s.......x......s"
			"sxxxxxxx.......s"
			"s.b.b.b........s"
			"sp.............s"
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



		//NOTE(ian): Flying levels ~4

		/*

		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"sbxx......bxxxxs"
			"sbx..........bxs"
			"sxb...........ps"
			"sx...........bxs"
			"sx.........xxxxs"
			"sx.............s"
			"sxxxxx.........s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"ssssssssssssssss";

		/*
		//NOTE(ian): this is a neat idea and it's much better! :)
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..............s"
			"s.........b....s"
			"sssss....bd.x..s"
			"s.........b....s"
			"s..............s"
			"s............x.s"
			"s..............s"
			"s............b.s"
			"sssss........x.s"
			"s............b.s"
			"s...........p..s"
			"s...........xxxs"
			"ssssssssssssssss";


		/*
		//NOTE(ian): this is really good! Keep/iterate

		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"ss.s.........s.s"
			"s.s...........ss"
			"ss.s.........s.s"
			"s.s...........ss"
			"ss.s.........s.s"
			"s.s...........ss"
			"ss.s.........s.s"
			"s.s....,....s.ss"
			"ss.s..bbb...bs.s"
			"s.s.s..p.b..sbss"
			"ss.s.s.b..b..s.s"
			"s.s.s...bb..s.ss"
			"ss.s.s.s...s.s.s"
			"ssssssssssssssss";


		/*
		//NOTE(ian): this is neat but is this the best way to present it?
		const char* Level =
			"ssssssssssssssss"
			"s.......s......s"
			"s.......sss....s"
			"s.........s....s"
			"s.........sss..s"
			"s...........s..s"
			"s...........ssss"
			"s..............s"
			"sss............s"
			"s.s.......bx...s"
			"s.sss..........s"
			"s...s.......b..s"
			"s...sss....b...s"
			"s.....s.....b.ps"
			"sssssssssxxxxxxs"
			"ssssssssssssssss";

		*/
		

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
		
		

		

		/*
			enum block_attributes {
			NO_ATTRIBUTE = 0,
			ACCEPTS_INPUT = 1,
			MOVING = 2,
			STATIONARY = 4,
			IS_ROTATABLE = 8,
			STATIC = 16,
			STICKS_TO_WALLS = 32,
			STICKS_TO_SPIKES = 64,
			STICKS_TO_PLAYER = 128,
			STICKS_TO_BLOCKS = 256
			};
		*/

		GameState.PlayerIndex = -1;
		for (s32 Y = 0;
			Y < LEVELHEIGHT;
			++Y)
		{
			for (s32 X = 0;
				X < LEVELWIDTH;
				++X)
			{
				GameState.Grid[Y*LEVELWIDTH + X].Move = i2{ 0,0 };

				if (Level[Y*LEVELWIDTH + X] == 'x')
				{
					GameState.Grid[(LEVELHEIGHT-Y-1)*LEVELWIDTH+X].Properties = InitializeChebyshevWallProperties();
				}
				else if (Level[Y*LEVELWIDTH + X] == 'p')
				{
					GameState.PlayerIndex = (u32)((LEVELHEIGHT-Y-1) * LEVELWIDTH + X);
					GameState.Grid[(LEVELHEIGHT - Y - 1)*LEVELWIDTH + X].Properties = InitializePlayerProperties();

				}
				else if (Level[Y*LEVELWIDTH + X] == 'b')
				{
					GameState.Grid[(LEVELHEIGHT - Y - 1)*LEVELWIDTH + X].Properties = InitializeChebyshevCrateProperties();
				}
				else if (Level[Y*LEVELWIDTH + X] == 'd')
				{
					GameState.Grid[(LEVELHEIGHT - Y - 1)*LEVELWIDTH + X].Properties = InitializeMetriclessCrateProperties();
				}
				else if (Level[Y*LEVELWIDTH + X] == 's')
				{
					GameState.Grid[(LEVELHEIGHT - Y - 1)*LEVELWIDTH + X].Properties = InitializeMetriclessWallProperties();
				}
				else if (Level[Y*LEVELWIDTH + X] == 'c')
				{
					GameState.Grid[(LEVELHEIGHT - Y - 1)*LEVELWIDTH + X].Properties = InitializeCreatureProperties();
				}
				else
				{
					//TODO(ian): make a helper function for null blocks
					GameState.Grid[(LEVELHEIGHT - Y - 1)*LEVELWIDTH + X].Properties = block_properties{ 0,0 };
				}
			}
		}
		
		GameState.TotalStateBytes = 0;
		GameState.TotalStateEntries = 0;


		Assert(GameState.PlayerIndex != -1);
		GameState.PreviousMove = i2{ 1,0 };
	}

	u8 SoundData[8192] = {0};
	b32 Running = true;
	user_input Input = { 0 };
	Input.dt = 1.0f / 60.0f;
	u64 BeginFrame = SDL_GetPerformanceCounter();
	u64 CountFrequency = SDL_GetPerformanceFrequency();
	SDL_PauseAudioDevice(AudioDeviceID, 0);


	Input.Up.KeyOne = SDL_SCANCODE_UP;
	Input.Up.KeyTwo = SDL_SCANCODE_W;

	Input.Down.KeyOne = SDL_SCANCODE_DOWN;
	Input.Down.KeyTwo = SDL_SCANCODE_S;
	
	
	Input.Left.KeyOne = SDL_SCANCODE_LEFT;
	Input.Left.KeyTwo = SDL_SCANCODE_A;
	
	
	Input.Right.KeyOne = SDL_SCANCODE_RIGHT;
	Input.Right.KeyTwo = SDL_SCANCODE_D;


	Input.Undo.KeyOne = SDL_SCANCODE_Z;
	Input.Undo.KeyTwo = SDL_SCANCODE_U;

	Input.Restart.KeyOne = SDL_SCANCODE_R;
	Input.Restart.KeyTwo = SDL_SCANCODE_R;

	r32 SecondCounter = 0.0f;
	u32 FPS = 0;
	

	while (Running)
	{
		if (SDL_QuitRequested())
		{
			Running = false;
		}
		const u8 *KeyboardState = SDL_GetKeyboardState(0);
		
		if ((Input.Up.CurrentPressed = (KeyboardState[Input.Up.KeyOne] || KeyboardState[Input.Up.KeyTwo])))
		{
			Input.Up.TimeHeld += Input.dt;
		}
		else
		{
			Input.Up.TimeHeld = 0.0f;
		}
		
		if ((Input.Down.CurrentPressed = (KeyboardState[Input.Down.KeyOne] || KeyboardState[Input.Down.KeyTwo])))
		{
			Input.Down.TimeHeld += Input.dt;
		}
		else
		{
			Input.Down.TimeHeld = 0.0f;
		}


		if ((Input.Left.CurrentPressed = (KeyboardState[Input.Left.KeyOne] || KeyboardState[Input.Left.KeyTwo])))
		{
			Input.Left.TimeHeld += Input.dt;
		}
		else
		{
			Input.Left.TimeHeld = 0.0f;
		}


		if ((Input.Right.CurrentPressed = (KeyboardState[Input.Right.KeyOne] || KeyboardState[Input.Right.KeyTwo])))
		{
			Input.Right.TimeHeld += Input.dt;
		}
		else
		{
			Input.Right.TimeHeld = 0.0f;
		}

		
		if ((Input.Undo.CurrentPressed = (KeyboardState[Input.Undo.KeyOne] || KeyboardState[Input.Undo.KeyTwo])))
		{
			Input.Undo.TimeHeld += Input.dt;
		}
		else
		{
			Input.Undo.TimeHeld = 0.0f;
		}


		if ((Input.Restart.CurrentPressed = (KeyboardState[Input.Restart.KeyOne] || KeyboardState[Input.Restart.KeyTwo])))
		{
			Input.Restart.TimeHeld += Input.dt;
		}
		else
		{
			Input.Restart.TimeHeld = 0.0f;
		}


		s32 BytesToWrite = (s32)sizeof(SoundData) - (s32)SDL_GetQueuedAudioSize(AudioDeviceID);

		WindowTexture.Texels = (u32*)Surface->pixels;
		GameUpdateAndRender(&GameState, &Input, &WindowTexture, SoundData, BytesToWrite,
			ObtainedAudio.samples);
		
		Input.Up.PreviousPressed = Input.Up.CurrentPressed;
		Input.Down.PreviousPressed = Input.Down.CurrentPressed;
		Input.Left.PreviousPressed = Input.Left.CurrentPressed;
		Input.Right.PreviousPressed = Input.Right.CurrentPressed;
		Input.Undo.PreviousPressed = Input.Undo.CurrentPressed;
		Input.Restart.PreviousPressed = Input.Restart.CurrentPressed;

		u64 MidFrame = SDL_GetPerformanceCounter();
		u64 UpdateTime = ((MidFrame - BeginFrame) * 1000) / CountFrequency;
		s32 WaitTime = 33 - (s32)UpdateTime;
		if (WaitTime > 0)
		{
			SDL_Delay(WaitTime);
		}

		SDL_UpdateWindowSurface(Window);
		SDL_QueueAudio(AudioDeviceID, (void*)SoundData, (u32)BytesToWrite);

		//SDL_Delay(1000);
		u64 EndFrame = SDL_GetPerformanceCounter();
		u64 FrameTime = ((EndFrame - BeginFrame) * 1000000) / CountFrequency;
		Input.dt = (r32)FrameTime / 1000000.0f;

		/*
		SecondCounter += Input.dt;
		++FPS;
		if (SecondCounter >= 1.0f)
		{
			printf("\nFPS: %d",FPS);
			SecondCounter -= 1.0f;
			FPS = 0;
		}
		*/


		//printf("FrameTime = %d . %d ms\n",FrameTime/1000, FrameTime%1000);
		//printf("FPS = %f\n", 1.0f / Input.dt);
		BeginFrame = EndFrame;
	}

	SDL_DestroyWindow(Window);
	SDL_Quit();
	return 0;
}
