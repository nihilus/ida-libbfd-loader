#define PACKAGE 1 /* Work-around for bfd.h */
#define PACKAGE_VERSION 1 /* Work-around for bfd.h */

#include <bfd.h>
#include <idaldr.h>

inline char *bfd_arch_to_ida(bfd_architecture bfd_arch, int bigendian){
/* Extracted from archures.c.  */
enum bfd_architecture
{
  bfd_arch_unknown,   /* File arch not known.  */
  bfd_arch_obscure,   /* Arch known, not one of these.  */
  bfd_arch_m68k,      /* Motorola 68xxx */
  bfd_arch_vax,       /* DEC Vax */
  bfd_arch_i960,      /* Intel 960 */
    /* The order of the following is important.
       lower number indicates a machine type that
       only accepts a subset of the instructions
       available to machines with higher numbers.
       The exception is the "ca", which is
       incompatible with all other machines except
       "core".  */

  bfd_arch_or1k,      /* OpenRISC 1000 */
  bfd_arch_sparc,     /* SPARC */
  bfd_arch_spu,       /* PowerPC SPU */
  bfd_arch_mips,      /* MIPS Rxxxx */
  bfd_arch_l1om,   /* Intel L1OM */
  bfd_arch_k1om,   /* Intel K1OM */
  bfd_arch_iamcu,   /* Intel MCU */
  bfd_arch_we32k,     /* AT&T WE32xxx */
  bfd_arch_tahoe,     /* CCI/Harris Tahoe */
  bfd_arch_i860,      /* Intel 860 */
  bfd_arch_i370,      /* IBM 360/370 Mainframes */
  bfd_arch_romp,      /* IBM ROMP PC/RT */
  bfd_arch_convex,    /* Convex */
  bfd_arch_m88k,      /* Motorola 88xxx */
  bfd_arch_m98k,      /* Motorola 98xxx */
  bfd_arch_pyramid,   /* Pyramid Technology */
  bfd_arch_h8300,     /* Renesas H8/300 (formerly Hitachi H8/300) */
  bfd_arch_pdp11,     /* DEC PDP-11 */
  bfd_arch_plugin,
  bfd_arch_powerpc,   /* PowerPC */
  bfd_arch_rs6000,    /* IBM RS/6000 */
  bfd_arch_hppa,      /* HP PA RISC */
  bfd_arch_d10v,      /* Mitsubishi D10V */
  bfd_arch_d30v,      /* Mitsubishi D30V */
  bfd_arch_dlx,       /* DLX */
  bfd_arch_m68hc11,   /* Motorola 68HC11 */
  bfd_arch_m68hc12,   /* Motorola 68HC12 */
  bfd_arch_m9s12x,   /* Freescale S12X */
  bfd_arch_m9s12xg,  /* Freescale XGATE */
  bfd_arch_z8k,       /* Zilog Z8000 */
  bfd_arch_h8500,     /* Renesas H8/500 (formerly Hitachi H8/500) */
  bfd_arch_sh,        /* Renesas / SuperH SH (formerly Hitachi SH) */
  bfd_arch_alpha,     /* Dec Alpha */
  bfd_arch_arm,       /* Advanced Risc Machines ARM.  */
  bfd_arch_nds32,     /* Andes NDS32 */
  bfd_arch_ns32k,     /* National Semiconductors ns32000 */
  bfd_arch_w65,       /* WDC 65816 */
  bfd_arch_tic30,     /* Texas Instruments TMS320C30 */
  bfd_arch_tic4x,     /* Texas Instruments TMS320C3X/4X */
  bfd_arch_tic54x,    /* Texas Instruments TMS320C54X */
  bfd_arch_tic6x,     /* Texas Instruments TMS320C6X */
  bfd_arch_tic80,     /* TI TMS320c80 (MVP) */
  bfd_arch_v850,      /* NEC V850 */
  bfd_arch_v850_rh850,/* NEC V850 (using RH850 ABI) */
  bfd_arch_arc,       /* ARC Cores */
  bfd_arch_m32c,     /* Renesas M16C/M32C.  */
  bfd_arch_m32r,      /* Renesas M32R (formerly Mitsubishi M32R/D) */
  bfd_arch_mn10200,   /* Matsushita MN10200 */
  bfd_arch_mn10300,   /* Matsushita MN10300 */
  bfd_arch_fr30,
  bfd_arch_frv,
  bfd_arch_moxie,       /* The moxie processor */
  bfd_arch_ft32,       /* The ft32 processor */
  bfd_arch_mcore,
  bfd_arch_mep,
  bfd_arch_metag,
  bfd_arch_ia64,      /* HP/Intel ia64 */
  bfd_arch_ip2k,      /* Ubicom IP2K microcontrollers. */
  bfd_arch_iq2000,     /* Vitesse IQ2000.  */
  bfd_arch_epiphany,   /* Adapteva EPIPHANY */
  bfd_arch_mt,
  bfd_arch_pj,
  bfd_arch_avr,       /* Atmel AVR microcontrollers.  */
  bfd_arch_bfin,        /* ADI Blackfin */
  bfd_arch_cr16,       /* National Semiconductor CompactRISC (ie CR16). */
  bfd_arch_cr16c,       /* National Semiconductor CompactRISC. */
  bfd_arch_crx,       /*  National Semiconductor CRX.  */
  bfd_arch_cris,      /* Axis CRIS */
  bfd_arch_riscv,
  bfd_arch_rl78,
  bfd_arch_rx,        /* Renesas RX.  */
  bfd_arch_s390,      /* IBM s390 */
  bfd_arch_score,     /* Sunplus score */
  bfd_arch_mmix,      /* Donald Knuth's educational processor.  */
  bfd_arch_xstormy16,
  bfd_arch_msp430,    /* Texas Instruments MSP430 architecture.  */
  bfd_arch_xc16x,     /* Infineon's XC16X Series.               */
  bfd_arch_xgate,   /* Freescale XGATE */
  bfd_arch_xtensa,    /* Tensilica's Xtensa cores.  */
  bfd_arch_z80,
  bfd_arch_lm32,      /* Lattice Mico32 */
  bfd_arch_microblaze,/* Xilinx MicroBlaze. */
  bfd_arch_tilepro,   /* Tilera TILEPro */
  bfd_arch_tilegx, /* Tilera TILE-Gx */
  bfd_arch_aarch64,   /* AArch64  */
  bfd_arch_nios2,      /* Nios II */
  bfd_arch_visium,     /* Visium */
  bfd_arch_wasm32,     /* WebAssembly */
  bfd_arch_pru,        /* PRU */
  bfd_arch_last
  };

	switch(bfd_arch){
		case bfd_arch_arm:
			if(bigendian)
				return "armb";
			else
				return "arm";
		case bfd_arch_mips:
			if(bigendian)
				return "mipsb";
			else
				return "mipsl";
		case bfd_arch_powerpc:
			if(bigendian)
				return "ppc";
			else
				return "ppcl";
		case bfd_arch_i386:
			return "metapc";
		case bfd_arch_m68k:
			return "68K";
		default:
			return "";
	}
}

//--------------------------------------------------------------------------
//
//  check input file format. if recognized, then return 1
//  and fill 'fileformatname'.
//  otherwise return 0
//
int idaapi accept_file(qstring *fileformatname, qstring *processor, linput_t *li, const char *filename)
{
	bfd *abfd = nullptr;
    msg("Testing BFD loader: %s\n", filename);
	bfd_init();
    abfd = bfd_openr(filename, nullptr);
    if(abfd == nullptr) {
        return 0;
    }
    if (!(bfd_check_format(abfd, bfd_object) /*|| bfd_check_format(abfd, bfd_archive)*/)) {
        bfd_close(abfd);
        return 0;
    }
    if((bfd_get_flavour(abfd) == bfd_target_elf_flavour) && (bfd_count_sections(abfd) == 0)){
        /* Parse ELF without section table with the ELF parser since it handles program headers */
		bfd_close(abfd);
		return 0;
    }
    bfd_architecture arch = bfd_get_arch(abfd);
    if(arch == bfd_arch_unknown || arch == bfd_arch_obscure){
	 	fileformatname->sprnt("BFD loader executable: Unknown arch.");
    } else {
    	fileformatname->sprnt("BFD loader executable: %s.", bfd_printable_arch_mach(arch, bfd_arch_bits_per_address(abfd)));
		*processor = bfd_arch_to_ida(arch, bfd_big_endian(abfd));
    }
    bfd_close(abfd);
    return 1;
}

//--------------------------------------------------------------------------
//
//  load file into the database.
//
//#define _CODE   0
//#define _DATA   1
//#define _BSS    2
//#define _STACK  3
//#define MAXSEG  2

void idaapi load_file(linput_t *li, ushort neflag, const char *fileformatname)
{
	set_processor_type("metapc", SETPROC_LOADER);
}

//----------------------------------------------------------------------
//
//      LOADER DESCRIPTION BLOCK
//
//----------------------------------------------------------------------
loader_t LDSC =
{
	IDP_INTERFACE_VERSION,
	0,
	accept_file,
	load_file,
	NULL,
	NULL,
	NULL,
};
