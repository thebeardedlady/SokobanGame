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

inline v2
V2(r32 X, r32 Y)
{
	v2 Result;
	Result.X = X;
	Result.Y = Y;
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

inline b32
WithinRenderRect(render_dim *Rect, s32 X, s32 Y)
{
	b32 Result = (X >= Rect->X && X < Rect->X + Rect->W) &&
		(Y >= Rect->Y && Y < Rect->Y + Rect->H);
	return Result;
}


//NOTE(ian): 2D Axis-aligned Boudning Box

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
	b32 Result = (A.X >= Rect.P.X && A.X <= Rect.P.X + Rect.Size.X) &&
		(A.Y >= Rect.P.Y && A.Y <= Rect.P.Y + Rect.Size.Y);
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

inline r2 MultiplePoints(v2* Points, u32 Num)
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
	EMPTY,
	PLAYER,
	WALL,
	SPIKE,
	CRATE,
	SOUL,
	CREATURE
};

enum block_attributes {
	NO_ATTRIBUTE = 0,
	ACCEPTS_INPUT = 1,
	MOVABLE = 2,
	STATIONARY = 4,
	ROTATABLE = 8,
	STICKS_TO_WALLS = 16,
	STICKS_TO_SPIKES = 32,
	STICKS_TO_PLAYER = 64,
	STICKS_TO_CRATES = 128,
	STICKS_TO_CREATURES = 256
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

enum groundedness {
	FLOATING,
	STANDING
};

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
	v2 Move;
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
	texture Texture;
	texture PlayerTexture;
	prng_state PRNG;
	u32 PlayerIndex;
	b32 DiagonalMove;
	b32 KilledEnemy;
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
InitializeSpikeProperties()
{
	return block_properties{ SPIKE,STATIONARY };
}

inline block_properties
InitializeCreatureProperties()
{
	return block_properties{ CREATURE,STICKS_TO_SPIKES | STICKS_TO_CREATURES | STICKS_TO_WALLS | MOVABLE };
}

inline block_properties
InitializePlayerProperties()
{
	return block_properties{ PLAYER,ACCEPTS_INPUT | STICKS_TO_CRATES | STICKS_TO_WALLS | MOVABLE };
}

inline block_properties
InitializeWallProperties()
{
	return block_properties{ WALL,STATIONARY };
}

inline block_properties
InitializeCrateProperties()
{
	return block_properties{ CRATE,STICKS_TO_CRATES | STICKS_TO_WALLS | MOVABLE };
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
IsWall(block_properties Properties)
{
	b32 Result = (Properties.Type == WALL);
	return Result;
}


inline b32
IsSpike(block_properties Properties)
{
	b32 Result = (Properties.Type == SPIKE);
	return Result;
}

inline b32
IsCrate(block_properties Properties)
{
	b32 Result = (Properties.Type == CRATE);
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
	AddUndo(Grid, PreviousState, TotalStateBytes, TotalStateEntries);

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
}


#define MAXMOVEABLES 20

internal b32
DetermineStickiness(block* Grid, u32* Indices, u32* NumIndices, u32 X, u32 Y)
{
	b32 NoFall = false;
	for (u32 I = 0;
		I < 3;
		++I)
	{
		for (u32 J = 0;
			J < 3;
			++J)
		{
			//TODO(ian): this is way to specific; is the rule universal or is it dependent on type?
			//TODO(ian): this causes an exception when player hits the edge of the level!!!
			u32 Index = (Y + I - 1)*LEVELWIDTH + X + J - 1;
			block SurroundingCell = Grid[Index];
			if (IsWall(SurroundingCell.Properties))
			{
				NoFall = true;
				break;
			}
			else if (IsCrate(SurroundingCell.Properties))
			{
				b32 Checked = false;
				for (u32 K = 0;
					K < *NumIndices;
					++K)
				{
					if (Index == Indices[K])
					{
						Checked = true;
						break;
					}
				}

				if (!Checked)
				{
					Indices[(*NumIndices)++] = Index;
					if ((NoFall = DetermineStickiness(Grid, Indices, NumIndices, X + J - 1, Y + I - 1)))
					{
						break;
					}
				}
			}
		}

		if (NoFall)
		{
			break;
		}
	}

	return NoFall;
}

internal b32
DetermineLinking(block* Grid, u32* Indices, u32* NumIndices, u32 X, u32 Y)
{
	b32 NoFall = false;
	for (u32 I = 0;
		I < 3;
		++I)
	{
		for (u32 J = 0;
			J < 3;
			++J)
		{
			//TODO(ian): this is way to specific; is the rule universal or is it dependent on type?
			//TODO(ian): this causes an exception when player hits the edge of the level!!!
			u32 Index = (Y + I - 1)*LEVELWIDTH + X + J - 1;
			block SurroundingCell = Grid[Index];
			if (IsWall(SurroundingCell.Properties) || IsSpike(SurroundingCell.Properties))
			{
				NoFall = true;
				break;
			}
			else if (IsCreature(SurroundingCell.Properties))
			{
				b32 Checked = false;
				for (u32 K = 0;
					K < *NumIndices;
					++K)
				{
					if (Index == Indices[K])
					{
						Checked = true;
						break;
					}
				}

				if (!Checked)
				{
					Indices[(*NumIndices)++] = Index;
					if ((NoFall = DetermineLinking(Grid, Indices, NumIndices, X + J - 1, Y + I - 1)))
					{
						break;
					}
				}
			}
		}

		if (NoFall)
		{
			break;
		}
	}

	return NoFall;
}

internal b32
DetermineFooting(block* Grid, u32* Indices, u32* NumIndices, u32 X, u32 Y)
{
	b32 NoFall = false;
	u32 PrimaryIndex = (Y + 1)*LEVELWIDTH + X;
	if (AreBitsSet(Grid[PrimaryIndex].Properties.Attributes, STATIONARY) || IsPlayer(Grid[PrimaryIndex].Properties))
	{
		return true;
	}

	for (u32 I = 0;
		I < 3;
		++I)
	{
		for (u32 J = 0;
			J < 3;
			++J)
		{
			if (I != 1 || J != 1)
			{
				//TODO(ian): this is way to specific; is the rule universal or is it dependent on type?
				//TODO(ian): this causes an exception when player hits the edge of the level!!!
				u32 Index = (Y + I - 1)*LEVELWIDTH + X + J - 1;
				block SurroundingCell = Grid[Index];
				if (IsCrate(SurroundingCell.Properties))
				{
					b32 Checked = false;
					for (u32 K = 0;
						K < *NumIndices;
						++K)
					{
						if (Index == Indices[K])
						{
							Checked = true;
							break;
						}
					}

					if (!Checked)
					{
						Indices[(*NumIndices)++] = Index;
						if ((NoFall = DetermineFooting(Grid, Indices, NumIndices, X + J - 1, Y + I - 1)))
						{
							break;
						}
					}
				}
			}
		}

		if (NoFall)
		{
			break;
		}
	}

	return NoFall;
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
			if (IsCrate(GameState->Grid[Index].Properties))
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
ApplyMoveToBlocks(game_state* GameState, u32* Indices, u32* NumIndices, v2 Move, u32 X, u32 Y)
{
	for (u32 I = 0;
		I < 3;
		++I)
	{
		for (u32 J = 0;
			J < 3;
			++J)
		{
			if (I != 1 || J != 1)
			{

				u32 Index = (Y + I - 1)*LEVELWIDTH + X + J - 1;
				if (IsCrate(GameState->Grid[Index].Properties))
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
						GameState->Grid[Index].Move = Move;
						ApplyMoveToBlocks(GameState, Indices, NumIndices, Move, X + J - 1, Y + I - 1);
					}
				}
			}
		}
	}
}

internal void
ImplementMovingRules(game_state* GameState, v2 Move)
{
	b32 FoundPlayer = false;
	for (u32 Y = 1;
		Y < LEVELHEIGHT - 2;
		++Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH - 2;
			++X)
		{
			if (IsPlayer(GameState->Grid[Y*LEVELWIDTH + X].Properties))
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

	u32 AdjacentIndex = ((GameState->PlayerIndex / LEVELWIDTH) + (u32)Move.Y) * LEVELWIDTH + ((u32)Move.X + GameState->PlayerIndex % LEVELWIDTH);

	/*
	{
		u32 Indices[30];
		u32 NumIndices = 0;
		if (!DetermineStickiness(GameState->Grid, Indices, NumIndices, AdjacentIndex%LEVELWIDTH, AdjacentIndex / LEVELWIDTH))
		{
			Move = { 0.0f,0.0f };
		}
	}
	*/




	// #1 1. Apply direction to player
	GameState->Grid[GameState->PlayerIndex].Move = Move;


	// 7. player against wall
	AdjacentIndex = ((GameState->PlayerIndex / LEVELWIDTH) + (u32)Move.Y) * LEVELWIDTH + ((u32)Move.X + GameState->PlayerIndex % LEVELWIDTH);
	if (IsWall(GameState->Grid[AdjacentIndex].Properties) || IsSpike(GameState->Grid[AdjacentIndex].Properties))
	{
		GameState->Grid[GameState->PlayerIndex].Move = v2{ 0.0f,0.0f };
	}
	else if (IsCreature(GameState->Grid[AdjacentIndex].Properties))
	{
		if (TLength(Move) > 1.0f)
		{
			GameState->KilledEnemy = true;
		}
		else
		{
			GameState->Grid[GameState->PlayerIndex].Move = v2{ 0.0f,0.0f };
		}
	}
	else if (GameState->Grid[AdjacentIndex].Properties.Type == 0)
	{
		u32 Indices[30];
		u32 NumIndices = 0;

		if (!DetermineStickiness(GameState->Grid, Indices, &NumIndices, AdjacentIndex%LEVELWIDTH, AdjacentIndex / LEVELWIDTH))
		{
			GameState->Grid[GameState->PlayerIndex].Move = v2{ 0.0f,0.0f };
		}
	}
	else if (IsCrate(GameState->Grid[AdjacentIndex].Properties)) // #2  player pushes block
	{
		GameState->Grid[AdjacentIndex].Move = Move;

		u32 Indices[30];
		u32 NumIndices = 0;

		u32 x = AdjacentIndex % LEVELWIDTH;
		u32 y = AdjacentIndex / LEVELWIDTH;
		ApplyMoveToBlocks(GameState, Indices, &NumIndices, Move, x, y);
	



		b32 FoundPattern;
		// #4 block against wall
		do {
			FoundPattern = false;
			for (u32 Y = 1;
				Y < LEVELHEIGHT - 1;
				++Y)
			{
				for (u32 X = 1;
					X < LEVELWIDTH - 1;
					++X)
				{
					block Cell = GameState->Grid[Y*LEVELWIDTH + X];
					if (IsCrate(Cell.Properties) && LengthSq(Cell.Move) > 0.0f)
					{
						u32 AdjacentIndex = (((Y*LEVELWIDTH + X) / LEVELWIDTH) + (u32)Cell.Move.Y) * LEVELWIDTH + ((u32)Cell.Move.X + (Y*LEVELWIDTH + X) % LEVELWIDTH);
						if (IsWall(GameState->Grid[AdjacentIndex].Properties) || IsSpike(GameState->Grid[AdjacentIndex].Properties) 
							|| IsPlayer(GameState->Grid[AdjacentIndex].Properties) || IsCreature(GameState->Grid[AdjacentIndex].Properties))
						{

							GameState->Grid[Y*LEVELWIDTH + X].Move = v2{ 0.0f,0.0f };
							FoundPattern = true;
						}
					}
				}
			}
		} while (FoundPattern);

		NumIndices = 0;
		if (!AreAllBlocksMoving(GameState, Indices, &NumIndices, x, y))
		{
			NumIndices = 0;
			Move = v2{ 0.0f,0.0f };
			ApplyMoveToBlocks(GameState, Indices, &NumIndices, Move, x, y);
		}


		/*
		// #5 block against stationary block
		do {
			FoundPattern = false;
			for (u32 Y = 1;
				Y < LEVELHEIGHT - 1;
				++Y)
			{
				for (u32 X = 1;
					X < LEVELWIDTH - 1;
					++X)
				{
					block Cell = GameState->Grid[Y*LEVELWIDTH + X];
					if (IsCrate(Cell.Properties) && LengthSq(Cell.Move) > 0.0f)
					{
						u32 AdjacentIndex = (((Y*LEVELWIDTH + X) / LEVELWIDTH) + (u32)Cell.Move.Y) * LEVELWIDTH + ((u32)Cell.Move.X + (Y*LEVELWIDTH + X) % LEVELWIDTH);
						if (IsCrate(GameState->Grid[AdjacentIndex].Properties) && LengthSq(GameState->Grid[AdjacentIndex].Move) == 0.0f)
						{
							GameState->Grid[Y*LEVELWIDTH + X].Move = v2{ 0.0f,0.0f };
							FoundPattern = true;
						}
					}
				}
			}
		} while (FoundPattern);
		*/


		// Player against stationary block
		if (IsCrate(GameState->Grid[AdjacentIndex].Properties) && LengthSq(GameState->Grid[AdjacentIndex].Move) == 0.0f)
		{
			GameState->Grid[GameState->PlayerIndex].Move = v2{ 0.0f,0.0f };
		}

		
		if (LengthSq(GameState->Grid[GameState->PlayerIndex].Move) == 0.0f)
		{
			for (u32 Y = 1;
				Y < LEVELHEIGHT - 1;
				++Y)
			{
				for (u32 X = 1;
					X < LEVELWIDTH - 1;
					++X)
				{
					GameState->Grid[Y*LEVELWIDTH + X].Move = v2{ 0.0f,0.0f };
				}
			}
		}
		
	}
}


internal void
EnactGravity(game_state* GameState)
{
	u32 BlockIndices[30];
	u32 Num = 0;
	block Blocks[30];
	b32 FoundPattern = false;
	for (u32 Y = LEVELHEIGHT - 1;
		Y > 0;
		--Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH - 1;
			++X)
		{
			block Cell = GameState->Grid[Y*LEVELWIDTH + X];
			if (IsCrate(Cell.Properties))
			{
				b32 NoFall;
				u32 VerticalCoord = Y, HorizontalNumIndices = 1, NumIndices = 0;
				u32 Indices[30];
				b32 Stickiness = DetermineStickiness(GameState->Grid, Indices, &NumIndices, X, VerticalCoord);
				NumIndices = 0;
				b32 Footing = DetermineFooting(GameState->Grid, Indices, &NumIndices, X, VerticalCoord);
				if (!Stickiness && !Footing)
				{
					BlockIndices[Num] = (Y+1) * LEVELWIDTH + X;
					Blocks[Num++] = Cell;
					FoundPattern = true;
				}
				else
				{
					BlockIndices[Num] = (Y) * LEVELWIDTH + X;
					Blocks[Num++] = Cell;
				}
			}
			else if (IsPlayer(Cell.Properties))
			{
				b32 NoFall;
				u32 VerticalCoord = Y, NumIndices = 1;
				u32 Indices[30];
				Indices[0] = Y * LEVELWIDTH + X;
				if (!DetermineStickiness(GameState->Grid, Indices, &NumIndices, X, VerticalCoord) && GameState->Grid && GameState->Grid[(VerticalCoord + 1)*LEVELWIDTH + X].Properties.Type == 0)
				{
					BlockIndices[Num] = (Y+1) * LEVELWIDTH + X;
					Blocks[Num++] = Cell;
					FoundPattern = true;
				}
				else
				{
					BlockIndices[Num] = (Y) * LEVELWIDTH + X;
					Blocks[Num++] = Cell;
				}
			}
			else if (IsCreature(Cell.Properties))
			{
				u32 Indices[30];
				u32 NumIndices = 1;
				Indices[0] = Y * LEVELWIDTH + X;
				if (!DetermineLinking(GameState->Grid, Indices, &NumIndices, X, Y))
				{
					BlockIndices[Num] = (Y + 1) * LEVELWIDTH + X;
					Blocks[Num++] = Cell;
					FoundPattern = true;
				}
				else
				{
					BlockIndices[Num] = (Y)* LEVELWIDTH + X;
					Blocks[Num++] = Cell;
				}
			}
		}
	}

	for (u32 Y = LEVELHEIGHT - 1;
		Y > 0;
		--Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH - 1;
			++X)
		{
			block Cell = GameState->Grid[Y*LEVELWIDTH + X];
			if (IsCrate(Cell.Properties) || IsPlayer(Cell.Properties))
			{
				GameState->Grid[Y*LEVELWIDTH + X] = block{ v2{ 0.0f,0.0f },block_properties{ 0,0 } };
			}
		}
	}


	for (u32 I = 0;
		I < Num;
		++I)
	{
		GameState->Grid[BlockIndices[I]] = Blocks[I];
	}
	//TODO(ian): change Player index here!!!1
}

internal void
ImplementCreatureRules(game_state* GameState)
{
	for (u32 Y = 1;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH;
			++X)
		{
			if (IsCreature(GameState->Grid[Y*LEVELWIDTH + X].Properties))
			{
				u32 Exes[9];
				u32 Whys[9];
				u32 NumPoints = 0;
				Exes[0] = X;
				Whys[0] = Y;
				++NumPoints;

				for (u32 I = 0;
					I < 3;
					++I)
				{
					for (u32 J = 0;
						J < 3;
						++J)
					{
						if (GameState->Grid[(Y+I-1)*LEVELWIDTH+X+J-1].Properties.Attributes == 0 || IsPlayer(GameState->Grid[(Y + I - 1)*LEVELWIDTH + X + J - 1].Properties))
						{
							b32 AroundCrate = false;
							for (u32 K = 0;
								K < 3;
								++K)
							{
								for (u32 L = 0;
									L < 3;
									++L)
								{
									if (IsCrate(GameState->Grid[(Y+I+K-2)*LEVELWIDTH + X+J+L-2].Properties))
									{
										AroundCrate = true;
										break;

									}
								}
								if (AroundCrate)
								{
									break;
								}
							}


							if (!AroundCrate)
							{
								Exes[NumPoints] = X + J-1;
								Whys[NumPoints++] = Y + I-1;
							}
						}
						else if (IsCrate(GameState->Grid[(Y + I-1)*LEVELWIDTH + X + J-1].Properties))
						{
							GameState->Grid[Y*LEVELWIDTH + X].Properties = InitializeCrateProperties();
						}
					}
				}

				

				u32 Indices[30];
				u32 NumIndices = 1;
				Indices[0] = Y * LEVELWIDTH + X;

				for (u32 I = NumPoints-1;
					I > 0;
					--I)
				{
					NumIndices = 1;

					if (!DetermineLinking(GameState->Grid, Indices, &NumIndices, Exes[I], Whys[I]))
					{
						--NumPoints;
						for (u32 J = I;
							J < NumPoints;
							++J)
						{
							Exes[J] = Exes[J + 1];
							Whys[J] = Whys[J + 1];
						}
					}
				}

				r32 MinDistance = 10000000.0f;
				u32 MinIndex = 0;
				for (u32 I = 0;
					I < NumPoints;
					++I)
				{
					r32 Distance = DistanceSq(v2{ (r32)(GameState->PlayerIndex%LEVELWIDTH),(r32)(GameState->PlayerIndex / LEVELWIDTH) }, v2{ (r32)Exes[I],(r32)Whys[I] });
					if (Distance < MinDistance)
					{
						MinDistance = Distance;
						MinIndex = I;
					}
				}

				//TODO(ian): change value to change how close creatrues become alerted
				r32 AlertDistance = 20.0f;
				if (MinDistance < AlertDistance)
				{
					GameState->Grid[Y*LEVELWIDTH + X].Move = v2{ (r32)((s32)(Exes[MinIndex] - X)),(r32)((s32)(Whys[MinIndex] - Y)) };
					int s = 0;
				}
			}
		}
	}
}

internal void
ExecuteTurn(game_state* GameState, u32 Pressed, u32 Held)
{

	GameState->DiagonalMove = GameState->KilledEnemy = false;
	

	for (u32 Y = 1;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH;
			++X)
		{
			GameState->Grid[Y*LEVELWIDTH + X].Move = v2{ 0.0f,0.0f };
		}
	}

	v2 Move = v2{ 0.0f,0.0f };

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
		if (AreBitsSet(Pressed, UP)) Move = v2{ 0.0f,-1.0f };
		else if (AreBitsSet(Pressed, DOWN)) Move = v2{ 0.0f,1.0f };
		else if (AreBitsSet(Pressed, LEFT)) Move = v2{ -1.0f,0.0f };
		else if (AreBitsSet(Pressed, RIGHT)) Move = v2{ 1.0f,0.0f };
	}
	else if (NumHeld == 1 && NumPressed == 0)
	{
		if (AreBitsSet(Held, UP)) Move = v2{ 0.0f,-1.0f };
		else if (AreBitsSet(Held, DOWN)) Move = v2{ 0.0f,1.0f };
		else if (AreBitsSet(Held, LEFT)) Move = v2{ -1.0f,0.0f };
		else if (AreBitsSet(Held, RIGHT)) Move = v2{ 1.0f,0.0f };
	}
	else if (NumHeld == 1 && NumPressed == 1)
	{
		if (AreBitsSet(Held, UP)) Move = v2{ 0.0f,-1.0f };
		else if (AreBitsSet(Held, DOWN)) Move = v2{ 0.0f,1.0f };
		else if (AreBitsSet(Held, LEFT)) Move = v2{ -1.0f,0.0f };
		else if (AreBitsSet(Held, RIGHT)) Move = v2{ 1.0f,0.0f };
	}



	// Rules: 

	// 0. get main direction
	// 1. apply direction to player
	// 2. player against wall or spike
	// 3. player pushes block
	// 3.5 block pushes its connected group of blocks
	// 4. block 90 degrees turn
	// 5. block against stationary block
	// 6. player against stationary block
	// 7. if player is blocked & two directions: add new direction
	// 8. repeat steps 2-6
	// 9. apply falling to blocks

	ImplementMovingRules(GameState, Move);

	if (LengthSq(GameState->Grid[GameState->PlayerIndex].Move) == 0.0f && NumPressed == 1 && NumHeld == 1)
	{
		if (AreBitsSet(Pressed, UP)) Move = Move + V2( 0.0f,-1.0f );
		else if (AreBitsSet(Pressed, DOWN)) Move = Move + V2( 0.0f,1.0f );
		else if (AreBitsSet(Pressed, LEFT)) Move = Move + V2(-1.0f, 0.0f);
		else if (AreBitsSet(Pressed, RIGHT)) Move = Move + V2( 1.0f,0.0f );

		for (u32 Y = 1;
			Y < LEVELHEIGHT - 1;
			++Y)
		{
			for (u32 X = 1;
				X < LEVELWIDTH - 1;
				++X)
			{
				GameState->Grid[Y*LEVELWIDTH + X].Move = v2{ 0.0f,0.0f };
			}
		}

		ImplementMovingRules(GameState, Move);
	}

	if (!GameState->KilledEnemy && LengthSq(GameState->Grid[GameState->PlayerIndex].Move) > 0.0f)
	{
		ImplementCreatureRules(GameState);
	}




	b32 AddingUndo = false;

	for (u32 Y = 1;
		Y < LEVELHEIGHT - 1;
		++Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH - 1;
			++X)
		{
			if (LengthSq(GameState->Grid[Y*LEVELWIDTH + X].Move) > 0.0f)
			{
				AddingUndo = true;
				break;
			}
		}
		if (AddingUndo)
		{
			break;
		}
	}

	if (AddingUndo && GameState->TotalStateBytes < MAX_UNDOS)
	{
		AddUndo(GameState->Grid, GameState->PreviousState, &GameState->TotalStateBytes, &GameState->TotalStateEntries);
	}
	else if (GameState->TotalStateBytes >= MAX_UNDOS)
	{
		printf("Out of Undos!!!!!!!");
	}
	

	// 8. Move everything
	block Moveables[30]; //TODO(ian): Maybe have dynamic data structure handle this?
	v2 Positions[30];
	u32 NumMoveables = 0;

	for (u32 Y = 1;
		Y < LEVELHEIGHT - 1;
		++Y)
	{
		for (u32 X = 1;
			X < LEVELWIDTH - 1;
			++X)
		{
			block Cell = GameState->Grid[Y*LEVELWIDTH + X];
			if (IsMoveable(Cell.Properties))
			{
				Moveables[NumMoveables] = Cell;
				Positions[NumMoveables] = V2((r32)X, (r32)Y);
				Moveables[NumMoveables++].Move = Cell.Move + Positions[NumMoveables];
				GameState->Grid[Y*LEVELWIDTH + X] = block{ v2{ 0.0f,0.0f },block_properties{0,0} };
			}
		}
	}


	for (u32 I = 0;
		I < NumMoveables;
		++I)
	{
		u32 Index = (u32)Moveables[I].Move.Y*LEVELWIDTH + (u32)Moveables[I].Move.X;
		for (u32 J = I+1;
			J < NumMoveables;
			++J)
		{
			u32 SecondIndex = (u32)Moveables[J].Move.Y*LEVELWIDTH + (u32)Moveables[J].Move.X;
			if (Index == SecondIndex)
			{
				if (IsCrate(Moveables[I].Properties))
				{
					printf("\nCrates are colliding with stuff!!!!");
					//NOTE(ian): None of this should happen!!!!
					if (IsCrate(Moveables[J].Properties))
					{

					}
					else if (IsPlayer(Moveables[J].Properties))
					{

					}
					else if (IsCreature(Moveables[J].Properties))
					{

					}
				}
				else if (IsPlayer(Moveables[I].Properties))
				{
					if (IsCrate(Moveables[J].Properties))
					{
						//NOTE(ian): this shouldn't happen!
						printf("\nCrates are colliding with the player!!!!");

					}
					else if (IsPlayer(Moveables[J].Properties))
					{
						//NOTE(ian): this shouldn't happen!!!
					}
					else if (IsCreature(Moveables[J].Properties))
					{
						if (GameState->KilledEnemy)
						{
							block Temp;
							Temp = Moveables[J];
							Moveables[J] = Moveables[I];
							Moveables[I] = Temp;
							v2 PTemp = Positions[J];
							Positions[J] = Positions[I];
							Positions[I] = PTemp;
						}
					}
				}
				else if (IsCreature(Moveables[I].Properties))
				{
					if (IsCrate(Moveables[J].Properties))
					{
						//NOTE(ian): this shouldn't happen!!!!
					}
					else if (IsPlayer(Moveables[J].Properties))
					{
						if (!GameState->KilledEnemy)
						{
							block Temp;
							Temp = Moveables[J];
							Moveables[J] = Moveables[I];
							Moveables[I] = Temp;
							v2 PTemp = Positions[J];
							Positions[J] = Positions[I];
							Positions[I] = PTemp;
						}
					}
					else if (IsCreature(Moveables[J].Properties))
					{
						Moveables[J].Move = Positions[J];
					}
				}
			}
		}
	}


	GameState->PlayerIndex = -1;
	for (u32 I = 0;
		I < NumMoveables;
		++I)
	{
		u32 Index = (u32)Moveables[I].Move.Y*LEVELWIDTH + (u32)Moveables[I].Move.X;
		GameState->Grid[Index] = Moveables[I];
		if (IsPlayer(Moveables[I].Properties))
		{
			GameState->PlayerIndex = Index;
		}
	}
}

internal void
GameUpdateAndRender(game_state *GameState, user_input *Input, texture *Window,
	u8 *SoundData, s32 BytesToWrite, u16 Samples)
{
	u64* TwoPixels = (u64*)Window->Texels;

	//NOTE(ian): Change these paramters to change the background
	u32 Bit = 3, Fit = 5;
	for (u32 Y = 0;
		Y < Window->Height / 2;
		++Y)
	{
		for (u32 X = 0;
			X < Window->Width;
			++X)
		{
			if ((((X + Y) / Fit) & ++Bit) == Bit--)
			{
				TwoPixels[Y * Window->Width + X] = 0;
			}
			else
			{
				TwoPixels[Y * Window->Width + X] = 0x00ffffff;
			}
		}
	}

	//block Blocks[30];
	//u32 NumIndices = 0;
	//u32 Indices[30]; 
	//CatalogConnectedBlocks(GameState, Blocks, Indices, &NumIndices, 6, 2);
	//5int r = 9;



	v2 Move = { 0 };
	r32 AgainTime = 0.25f;
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

	


	if (!Pressed && Held)
	{
		if (AreBitsSet(Held, UP))
		{
			Move = v2{ 0.0f,-1.0f };
		}
		
		if (AreBitsSet(Held, DOWN))
		{
			Move = v2{ 0.0f,1.0f };
		}

		if (AreBitsSet(Held, LEFT))
		{
			Move = v2{ -1.0f,0.0f };
		}

		if (AreBitsSet(Held, RIGHT))
		{
			Move = v2{ 1.0f,0.0f };
		}
	}
	else
	{
		if (AreBitsSet(Pressed, UP))
		{
			Move = v2{ 0.0f,-1.0f };
		}

		if (AreBitsSet(Pressed, DOWN))
		{
			Move = v2{ 0.0f,1.0f };
		}

		if (AreBitsSet(Pressed, LEFT))
		{
			Move = v2{ -1.0f,0.0f };
		}

		if (AreBitsSet(Pressed, RIGHT))
		{
			Move = v2{ 1.0f,0.0f };
		}
	}


	

	b32 NoFall = true;
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
				if (IsCrate(GameState->Grid[Y*LEVELWIDTH + X].Properties))
				{
					NumIndices = 0;
					b32 Footing = DetermineFooting(GameState->Grid, Indices, &NumIndices, X, Y);
					NumIndices = 0;
					b32 Stickiness = DetermineStickiness(GameState->Grid, Indices, &NumIndices, X, Y);
					if (!Footing && !Stickiness)
					{
						NoFall = false;
						break;
					}
				}
				else if (IsPlayer(GameState->Grid[Y*LEVELWIDTH + X].Properties))
				{
					GameState->PlayerIndex = Y * LEVELWIDTH + X;
					NumIndices = 0;
					if ((!DetermineStickiness(GameState->Grid, Indices, &NumIndices, X, Y)) && GameState->Grid[(Y+1)*LEVELWIDTH+X].Properties.Type == 0)
					{
						NoFall = false;
						break;
					}
				}
				else if (IsCreature(GameState->Grid[Y*LEVELWIDTH + X].Properties))
				{
					NumIndices = 1;
					Indices[0] = Y * LEVELWIDTH + X;
					b32 Linking = DetermineLinking(GameState->Grid, Indices, &NumIndices, X, Y);
					NumIndices = 0;
					b32 Footing = DetermineFooting(GameState->Grid, Indices, &NumIndices, X, Y);
					
					if (!Footing && !Linking)
					{
						NoFall = false;
						break;
					}
				}
			}
			if (!NoFall)
			{
				break;
			}
		}
	}



	GameState->AgainTime += Input->dt;
	if (NoFall)
	{
		if (LengthSq(Move) != 0.0f && GameState->PlayerIndex != -1)
		{
			ExecuteTurn(GameState, Pressed, Held);
			GameState->AgainTime = 0.0f;
		}
	}
	else
	{
		if (GameState->AgainTime >= AgainTime)
		{
			GameState->AgainTime -= AgainTime;
			EnactGravity(GameState);
		}
	}


	





	for (u32 Y = 0;
		Y < LEVELHEIGHT;
		++Y)
	{
		for (u32 X = 0;
			X < LEVELWIDTH;
			++X)
		{
			block_properties Field = GameState->Grid[Y*LEVELWIDTH + X].Properties;
			if (IsWall(Field))
			{
				DrawRect(*Window, GameState->Screen, r2{ v2{(r32)X,(r32)Y},v2{1.0f,1.0f} }, v4{ 0.7f,0.8f,1.0f,1.0f });
			}
			else if (IsPlayer(Field))
			{
				DrawRect(*Window, GameState->PlayerTexture, GameState->Screen, r2{ v2{ (r32)X,(r32)Y },v2{ 1.0f,1.0f } });
			}
			else if (IsCrate(Field))
			{
				DrawRect(*Window, GameState->Texture, GameState->Screen, r2{ v2{ (r32)X,(r32)Y },v2{ 1.0f,1.0f } });
			}
			else if (IsSpike(Field))
			{
				DrawRect(*Window, GameState->Screen, r2{ v2{ (r32)X,(r32)Y },v2{ 1.0f,1.0f } }, v4{ 0.5f,0.2f,0.045f,1.0f });
			}
			else if (IsCreature(Field))
			{
				DrawRect(*Window, GameState->Screen, r2{ v2{ (r32)X,(r32)Y },v2{ 1.0f,1.0f } }, v4{ 0.3f,0.9f,0.645f,1.0f });
			}
		}
	}

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
		GameState.AgainTime = 0.0f;
		Seed(&GameState.PRNG, 100);

		GameState.Texture.Width = 64;
		GameState.Texture.Height = 64;
		GameState.Texture.Texels = (u32*)AllocateChunk(GameState.Texture.Width*GameState.Texture.Height * sizeof(u32));
		
		v2 Point = v2{ 0.0f,0.0f };

		for (u32 y = 0;
			y < GameState.Texture.Height;
			++y)
		{
			for (u32 x = 0;
				x < GameState.Texture.Width;
				++x)
			{
				u32 r, g, b;
				//r = 255 - (u32)(TDistance(Point, Center) * 255.0f/MaxT);
				//g = 255 - (u32)(CDistance(Point, Center) * 255.0f / MaxC);
				//b = 255 - (u32)(Distance(Point, Centerg) * 255.0f / MaxE);
				if (x+y <= GameState.Texture.Width)
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


				GameState.Texture.Texels[y*GameState.Texture.Width + x] = (r << 16) | (g << 8) | b;

				Point.X += 1.0f;
			}

			Point.X = 0.0f;
			Point.Y += 1.0f;
		}

		GameState.PlayerTexture.Width = 64;
		GameState.PlayerTexture.Height = 64;
		GameState.PlayerTexture.Texels = (u32*)AllocateChunk(GameState.Texture.Width*GameState.Texture.Height * sizeof(u32));

		v2 Center = v2{ (r32)GameState.Texture.Width * -0.5f,(r32)GameState.Texture.Height * 0.5f };
		Point = Center;
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

		//Number of puzzles so far: ~10


		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..ss.xxxx.....s"
			"sssss.x......c.s"
			"s..ss.x.....ssss"
			"s..ss.x.....ssss"
			"s.....xx....s..s"
			"s.....x..s.....s"
			"s...b...sb..sxxs"
			"sxxx..xxxs.....s"
			"s..x..x..s.....s"
			"s..xb.x..s.....s"
			"sp....x..s.....s"
			"sxxxxxx........s"
			"ssssssssssssssss";

		/*
		//NOTE(ian): keep/iterate; this might be the better version of the one below

		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..ss.xxxx.....s"
			"sssss.x........s"
			"s..ss.x.....ssss"
			"s..ss.x.....ssss"
			"s.....xx.......s"
			"s.....x..s.....s"
			"s...b...sb..sxxs"
			"sxxx..xxxs.....s"
			"s..x..x..s.....s"
			"s..xb.x..s.....s"
			"sp....x..s.....s"
			"sxxxxxx........s"
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
			"s...........b..s"
			"s...........x..s"
			"s..............s"
			"s............p.s"
			"sssssssssssxxxxs"
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


		/*



		//NOTE(ian): keep/iterate - this concept should be taught
		const char* Level =
			"ssssssssssssssss"
			"s......x.......s"
			"s......x.......s"
			"s......x.......s"
			"s......x.......s"
			"s......x.......s"
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
		//NOTE(ian): keep/iterate - this is pretty cool
		
		const char* Level =
			"ssssssssssssssss"
			"sx.............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s...x..........s"
			"s....s.........s"
			"s.....s........s"
			"s......s.x.....s"
			"s.........s....s"
			"s..........s...s"
			"sb..........s..s"
			"s.b..........x.s"
			"s..b....p......s"
			"sxxxxxxxxxxxxxxs"
			"ssssssssssssssss";


		//NOTE(ian): keep/iterate - should i have this

		const char* Level =
			"ssssssssssssssss"
			"sx.............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"sx.x.x.x.x.x.x.s"
			"s.x.x.x.x.x.x.xs"
			"sx.x.x.x.x.x.x.s"
			"s.x.x.x.x.x.x.xs"
			"s..............s"
			"s..b.b.b.......s"
			"s.b.b.b........s"
			"s..b.b.b...p...s"
			"sxxxxxxxxxxxxxxs"
			"ssssssssssssssss";
		


		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s.....xxx......s"
			"sxxxxxxbxxxxxxxs"
			"sp.b...........s"
			"sxxxxxxbxxxxxxxs"
			"s.....xxx......s"
			"s..............s"
			"s..............s"
			"s..............s"
			"ssssssssssssssss";
		*/
		
		
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
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s....b..b......s"
			"s....x..x......s"
			"s..............s"
			"s............p.s"
			"sxxxxxxxbxxxxxxs"
			"sxxx....bxxxxxxs"
			"sxxx...b.xxxxxxs"
			"sxxx...b.xxxxxxs"
			"sxxx..b..xxxxxxs"
			"sxxx..b..xxxxxxs"
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

		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"ss.s.s.....s.s.s"
			"s.s.s..b..s.s.ss"
			"ss.s.s..bs.s.s.s"
			"s.s.s....bs.s.ss"
			"ss.s.s...s.s.s.s"
			"s.s.s.....s.s.ss"
			"ss.s.s..bs.sbs.s"
			"s.s.s..bs.sbspss"
			"ss.s..b.bs.sbs.s"
			"s.s.s..p.bs.sbss"
			"ss.s.s.b.sbs.s.s"
			"s.s.s..b.bs.s.ss"
			"ss.s.s.sbs.s.s.s"
			"ssssssssssssssss";


		/*
		const char* Level =
			"ssssssssssssssss"
			"sx.............s"
			"s.....s........s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s.....s.s.s.s..s"
			"s....sbsbsbsbs.s"
			"s.....s.s.s.s..s"
			"s......p.......s"
			"sxxxxxxxxxxxxxxs"
			"s..............s"
			"s..............s"
			"s..............s"
			"sx.............s"
			"ssssssssssssssss";
		
		*/
		
		/*
		//NOTE(ian): reprise!!
		const char* Level =
			"ssssssssssssssss"
			"s............xxs"
			"s.....x.xb.....s"
			"s.....x.sss....s"
			"s.......x......s"
			"s.......s......s"
			"s.p..b..s......s"
			"sxxxxxx.s......s"
			"s.....sss......s"
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
			"s............xxs"
			"s.......xb.....s"
			"s.......x......s"
			"s.......x......s"
			"s.......s......s"
			"s.p..b..s......s"
			"sxxxxxx.s......s"
			"s.......s......s"
			"s..............s"
			"s......x.......s"
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
			"s.........bb...s"
			"s.........bbb..s"
			"s.p.......bbb..s"
			"sxxxxxx..xxxxxxs"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"ssssssssssssssss";
		*/	

		/*
		//TODO(ian): this isn't very good; try to find something interesting about this
		const char* Level =
			"ssssssssssssssss"
			"ssssss..b......s"
			"sssssss.x......s"
			"ssssss....b....s"
			"ssssss....x....s"
			"ssss.......p...s"
			"s..........b...s"
			"s..........x...s"
			"s.......s.xxxxxs"
			"s.......s......s"
			"s.......sss....s"
			"ssssx..........s"
			"s..............s"
			"s..sss.........s"
			"sx.............s"
			"ssssssssssssssss";
		

		/*
		//NOTE(ian): this is pretty good. Keep/iterate upon this concept!!!
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..............s"
			"spb.b.b.b......s"
			"sxxxxxxxs......s"
			"s......s.......s"
			"s......s.......s"
			"s..............s"
			"s.............bs"
			"s...........xxxs"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"ssssssssssssssss";


		//TODO(ian): check this puzzle!!!
		const char* Level =
			"ssssssssssssssss"
			"s..............s"
			"s..............s"
			"s..............s"
			"spb.b.b.b....xss"
			"sxxxxxxxs...ssss"
			"s......s.......s"
			"s......s.......s"
			"s..............s"
			"s.............bs"
			"s...........xxxs"
			"s..............s"
			"s..............s"
			"s..............s"
			"s..............s"
			"ssssssssssssssss";
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
		for (u32 Y = 0;
			Y < LEVELHEIGHT;
			++Y)
		{
			for (u32 X = 0;
				X < LEVELWIDTH;
				++X)
			{
				GameState.Grid[Y*LEVELWIDTH + X].Move = v2{ 0.0f,0.0f };

				if (Level[Y*LEVELWIDTH + X] == 'x')
				{
					GameState.Grid[Y*LEVELWIDTH+X].Properties = InitializeWallProperties();
				}
				else if (Level[Y*LEVELWIDTH + X] == 'p')
				{
					GameState.PlayerIndex = Y * (u32)LEVELWIDTH + X;
					GameState.Grid[Y*LEVELWIDTH + X].Properties = InitializePlayerProperties();

				}
				else if (Level[Y*LEVELWIDTH + X] == 'b')
				{
					GameState.Grid[Y*LEVELWIDTH + X].Properties = InitializeCrateProperties();
				}
				else if (Level[Y*LEVELWIDTH + X] == 's')
				{
					GameState.Grid[Y*LEVELWIDTH + X].Properties = InitializeSpikeProperties();
				}
				else if (Level[Y*LEVELWIDTH + X] == 'c')
				{
					GameState.Grid[Y*LEVELWIDTH + X].Properties = InitializeCreatureProperties();
				}
				else
				{
					//TODO(ian): make a helper function for null blocks
					GameState.Grid[Y*LEVELWIDTH + X].Properties = block_properties{ 0,0 };
				}
			}
		}
		
		GameState.TotalStateBytes = 0;
		GameState.TotalStateEntries = 0;


		Assert(GameState.PlayerIndex != -1);
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
