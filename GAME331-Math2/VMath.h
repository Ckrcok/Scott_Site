#pragma once 
#include <math.h>
#include <stdio.h>

/// This is a library of Vec3 math routines. 

#include "Vector.h"

namespace  GAME_Lib {

	class VMath {

	public:
		/// Calculate the dot product between Vec3s a & b 
		inline static float dot(const Vec3 &a, const Vec3 &b){
			return((a.x * b.x + a.y * b.y + a.z * b.z));
		}

		/// Calulate the cross product
		inline static const Vec3 cross(const Vec3 &a, const Vec3 &b){
			return Vec3(a.y * b.z - a.z * b.y,
						a.z * b.x - a.x * b.z,
						a.x * b.y - a.y * b.x);
		}

		/// Return a normalized Vec3
		inline static Vec3 normalize(const Vec3 &a){
			float magnitude;
			Vec3 result;
			magnitude = float(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
			/// The Vector class watches for divide by zero errors
			result.x = a.x / magnitude;
			result.y = a.y / magnitude;
			result.z = a.z / magnitude;
			return result;
		}
		
		inline static float mag(const Vec3 &a){
			return(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
		}

		///  Angle-Axis rotation
		inline static Vec3 rotate(const Vec3 &n, float theta, const Vec3 &v){
			return v * cos(theta) + VMath::dot(v,n) * n * (1-cos(theta)) + VMath::cross(n,v) * sin(theta);
		}




		////////////////////////////////////////////////////////////////////////		
		/// These are a little more complex so I won't inline them
		////////////////////////////////////////////////////////////////////////
		/// Reflect a normalized direction Vec3 off a plane 
		static Vec3 reflect(const Vec3 v, const Plane p);

		/// Reflect a velocity Vec3 off a plane maintaining the original velocity 
		static Vec3 reflect2(const Vec3 v, const Plane p);

		/// Get the distance between two Vec3s 
		static float distance(const Vec3 &a, const Vec3 &b);

		/// Get the distance between a point (Vec3) and a plane 
		static float distance(const Vec3 &v, const Plane &p);

		/// Get the distance between a sphere and a plane
		static float distance(const Sphere &s, const Plane &p);

	};

}