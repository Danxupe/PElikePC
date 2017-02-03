#include <Substrate.h>
#include <jni.h>
#include <cmath>
#include <dlfcn.h>

#include "mcpe/block/Block.h"
#include "mcpe/block/BlockGraphics.h"
#include "mcpe/client/renderer/BlockTessellator.h"
#include "mcpe/client/renderer/Tessellator.h"
#include "mcpe/entity/player/LocalPlayer.h"
#include "mcpe/util/FullBlock.h"
#include "mcpe/level/Level.h"

#include "PElikePC/BlockTessellator/Armorstand.h"
//Hook real
bool (*tessellateInWorld_)(BlockTessellator*,Block const&,BlockPos const&,uchar,bool)=0;

bool tessellateInWorld(BlockTessellator*bt,Block const&block,BlockPos const&pos,uchar aux,bool b)
{
		switch(block.blockId) {
		case 41: 
		     return ((ArmorstandTessellator*)bt)->tessellate(block,pos,aux,b);
		default:
		return tessellateInWorld_(bt,block,pos,aux,b);
		}
}

JNIEXPORT jint JNI_OnLoad(JavaVM*,void*)
{
	void* imageRef=dlopen("libminecraftpe.so",RTLD_LAZY);
	MSHookFunction(dlsym(imageRef,"_ZN16BlockTessellator17tessellateInWorldERK5BlockRK8BlockPoshb"),(void*)&tessellateInWorld,(void**)&tessellateInWorld_);

	return JNI_VERSION_1_6;
}
