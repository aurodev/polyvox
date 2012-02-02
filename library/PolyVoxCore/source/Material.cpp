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

#include "PolyVoxCore/Material.h"

#include <cfloat> //Can't use <limits> as we need compile time constants.

namespace PolyVox
{	
	const bool VoxelTypeTraits< MaterialU8 >::HasDensity = false;
	const bool VoxelTypeTraits< MaterialU8 >::HasMaterial = true;
	const MaterialU8::DensityType VoxelTypeTraits< MaterialU8 >::MinDensity = 0;
	const MaterialU8::DensityType VoxelTypeTraits< MaterialU8 >::MaxDensity = 0;

	const bool VoxelTypeTraits< MaterialU16 >::HasDensity = false;
	const bool VoxelTypeTraits< MaterialU16 >::HasMaterial = true;
	const MaterialU16::DensityType VoxelTypeTraits< MaterialU16 >::MinDensity = 0;
	const MaterialU16::DensityType VoxelTypeTraits< MaterialU16 >::MaxDensity = 0;

	const bool VoxelTypeTraits< MaterialU32 >::HasDensity = false;
	const bool VoxelTypeTraits< MaterialU32 >::HasMaterial = true;
	const MaterialU32::DensityType VoxelTypeTraits< MaterialU32 >::MinDensity = 0;
	const MaterialU32::DensityType VoxelTypeTraits< MaterialU32 >::MaxDensity = 0;
}