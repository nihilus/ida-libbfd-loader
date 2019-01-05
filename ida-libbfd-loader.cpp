
#include "../idaldr.h"

//----------------------------------------------------------------------
//
//      LOADER DESCRIPTION BLOCK
//
//----------------------------------------------------------------------
__declspec(dllexport) loader_t LDSC =
{
	IDP_INTERFACE_VERSION,
	0,
	accept_file,
	load_file,
	save_file,
	NULL,
	NULL,
};
