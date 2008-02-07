#ifndef __Constants_H__
#define __Constants_H__

#include "boost/cstdint.hpp"

namespace Ogre
{
	//FIXME - i think we can define mod using a bitmask which flattens the upper bits. Should define that here.
	const boost::uint32_t OGRE_BLOCK_SIDE_LENGTH_POWER = 5;
	const boost::uint32_t OGRE_BLOCK_SIDE_LENGTH = (0x0001 << OGRE_BLOCK_SIDE_LENGTH_POWER);
	const boost::uint32_t OGRE_NO_OF_VOXELS_IN_BLOCK = (OGRE_BLOCK_SIDE_LENGTH * OGRE_BLOCK_SIDE_LENGTH * OGRE_BLOCK_SIDE_LENGTH);

	const boost::uint32_t OGRE_VOLUME_SIDE_LENGTH_POWER = 8;
	const boost::uint32_t OGRE_VOLUME_SIDE_LENGTH = (0x0001 << OGRE_VOLUME_SIDE_LENGTH_POWER);
	const boost::uint32_t OGRE_VOLUME_SIDE_LENGTH_IN_BLOCKS = (OGRE_VOLUME_SIDE_LENGTH >> OGRE_BLOCK_SIDE_LENGTH_POWER);
	const boost::uint32_t OGRE_NO_OF_BLOCKS_IN_VOLUME = (OGRE_VOLUME_SIDE_LENGTH_IN_BLOCKS * OGRE_VOLUME_SIDE_LENGTH_IN_BLOCKS * OGRE_VOLUME_SIDE_LENGTH_IN_BLOCKS);
	const boost::uint32_t OGRE_NO_OF_VOXELS_IN_VOLUME = (OGRE_VOLUME_SIDE_LENGTH * OGRE_VOLUME_SIDE_LENGTH * OGRE_VOLUME_SIDE_LENGTH);

	const boost::uint32_t OGRE_REGION_SIDE_LENGTH_POWER = 4;
	const boost::uint32_t OGRE_REGION_SIDE_LENGTH = (0x0001 << OGRE_REGION_SIDE_LENGTH_POWER);
	const boost::uint32_t OGRE_VOLUME_SIDE_LENGTH_IN_REGIONS = (OGRE_VOLUME_SIDE_LENGTH >> OGRE_REGION_SIDE_LENGTH_POWER);
	const boost::uint32_t OGRE_NO_OF_REGIONS_IN_VOLUME = (OGRE_VOLUME_SIDE_LENGTH_IN_REGIONS * OGRE_VOLUME_SIDE_LENGTH_IN_REGIONS * OGRE_VOLUME_SIDE_LENGTH_IN_REGIONS);

	const boost::uint32_t OGRE_MAX_VOXELS_TO_BURN_PER_FRAME = 1000;
}

#endif
