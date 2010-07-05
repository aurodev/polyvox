#pragma region License
/*******************************************************************************
Copyright (c) 2005-2009 David Williams

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution. 	
*******************************************************************************/
#pragma endregion

#ifndef __PolyVox_Vector_H__
#define __PolyVox_Vector_H__

#pragma region Headers
#include "PolyVoxForwardDeclarations.h"

#include <iostream>
#pragma endregion

namespace PolyVox
{
	/**
	Represents a vector in space.
	
	This Vector class is templated on both size and data type. It is designed to be
	generic but so far had only been tested with vectors of size 2 and 3. Also note
	that some of the operations do not make sense with integer types, for example it
	does not make conceptual sense to try and normalise an integer Vector.

	The elements of the Vector are accessed via the overloaded () operator which takes
	an index indicating the element to fetch. They are set using the set() function which
	takes an index indicating the element to set and a new value for that element. For
	convienience, the functions getX(), setX(), getY(), setY(), getZ(), setZ(), getw() and setW() 
	do the same thing for the first 4 elements of the Vector. 

	A variety of overloaded operators are also provided for comparison and arithmetic
	operations. For most of these arithmetic operators only the unary versions are 
	documented below - however often binary versions are also generated by std::operators.

	Lastly, note that for convienience a set of typedefs are included for 2 and 3 dimensional
	vectors with type float, double, int32_t, and uint32_t. They are used as follows:

	\code
	Vector2DInt4 test(1,2); //Declares a 2 dimensional Vector of type int4.
	\endcode
	*/
	template <uint32_t Size, typename Type>
	class Vector
    {
    public:
        ///Constructor.
        Vector(Type x, Type y) throw();
		///Constructor.
		Vector(Type x, Type y, Type z) throw();
		///Constructor.
		Vector(Type x, Type y, Type z, Type w) throw();
		///Constructor
		Vector(void) throw();
        ///Copy Constructor.
        Vector(const Vector<Size,Type>& vector) throw();
		///Copy Constructor which performs casting.
		template <typename CastType> explicit Vector(const Vector<Size,CastType>& vector) throw();
        ///Destructor.
        ~Vector(void) throw();

        ///Assignment Operator.
        Vector<Size,Type>& operator=(const Vector<Size,Type>& rhs) throw();
        ///Equality Operator.
        bool operator==(const Vector<Size,Type>& rhs) const throw();
		///Comparison Operator.
        bool operator<(const Vector<Size,Type>& rhs) const throw();
        ///Addition and Assignment Operator.
        Vector<Size,Type>& operator+=(const Vector<Size,Type> &rhs) throw();
        ///Subtraction and Assignment Operator.
        Vector<Size,Type>& operator-=(const Vector<Size,Type> &rhs) throw();
        ///Multiplication and Assignment Operator.
        Vector<Size,Type>& operator*=(const Type& rhs) throw();
        ///Division and Assignment Operator.
        Vector<Size,Type>& operator/=(const Type& rhs) throw();

		///Element Access.
		Type getElement(uint32_t index) const throw();
        ///Get the x component of the vector.
        Type getX(void) const throw();        
        ///Get the y component of the vector.
        Type getY(void) const throw();        
        ///Get the z component of the vector.
        Type getZ(void) const throw();        
		///Get the w component of the vector.
		Type getW(void) const throw();		

		///Element Access.
		void setElement(uint32_t index, Type tValue) throw();
		///Element Access.
        void setElements(Type x, Type y) throw();
		///Element Access.
		void setElements(Type x, Type y, Type z) throw();
		///Element Access.
		void setElements(Type x, Type y, Type z, Type w) throw();
		///Set the x component of the vector.
		void setX(Type tX) throw();
		///Set the y component of the vector.
		void setY(Type tY) throw();
		///Set the z component of the vector.
		void setZ(Type tZ) throw();
		///Set the w component of the vector.
		void setW(Type tW) throw();

        ///Get the length of the vector.
        double length(void) const throw();
        ///Get the squared length of the vector.
        double lengthSquared(void) const throw();
        ///Find the angle between this vector and that which is passed as a parameter.
        double angleTo(const Vector<Size,Type>& vector) const throw();
        ///Find the cross product between this vector and the vector passed as a parameter.
        Vector<Size,Type> cross(const Vector<Size,Type>& vector) const throw();
        ///Find the dot product between this vector and the vector passed as a parameter.
        Type dot(const Vector<Size,Type>& rhs) const throw();
        ///Normalise the vector.
        void normalise(void) throw();

    private:
        //Values for the vector
		Type m_tElements[Size];
    };

    //Non-member overloaded operators. 
	///Addition operator.
	template <uint32_t Size,typename Type>
	    Vector<Size,Type> operator+(const Vector<Size,Type>& lhs, const Vector<Size,Type>& rhs) throw();
	///Subtraction operator.
	template <uint32_t Size,typename Type>
	    Vector<Size,Type> operator-(const Vector<Size,Type>& lhs, const Vector<Size,Type>& rhs) throw();
	///Multiplication operator.
	template <uint32_t Size,typename Type>
	    Vector<Size,Type> operator*(const Vector<Size,Type>& lhs, const Type& rhs) throw();
	///Division operator.
	template <uint32_t Size,typename Type>
	    Vector<Size,Type> operator/(const Vector<Size,Type>& lhs, const Type& rhs) throw();
    ///Stream insertion operator.
    template <uint32_t Size, typename Type>
        std::ostream& operator<<(std::ostream& os, const Vector<Size,Type>& vector) throw();

	//Some handy typedefs
	///A 3D Vector of floats.
	typedef Vector<3,float> Vector3DFloat;
	///A 3D Vector of doubles.
    typedef Vector<3,double> Vector3DDouble;
	///A 3D Vector of signed 8-bit values.
	typedef Vector<3,int8_t> Vector3DInt8;
	///A 3D Vector of unsigned 8-bit values.
	typedef Vector<3,uint8_t> Vector3DUint8;
	///A 3D Vector of signed 16-bit values.
	typedef Vector<3,int16_t> Vector3DInt16;
	///A 3D Vector of unsigned 16-bit values.
	typedef Vector<3,uint16_t> Vector3DUint16;
	///A 3D Vector of signed 32-bit values.
	typedef Vector<3,int32_t> Vector3DInt32;
	///A 3D Vector of unsigned 32-bit values.
	typedef Vector<3,uint32_t> Vector3DUint32;



}//namespace PolyVox

#include "Vector.inl"

#endif

