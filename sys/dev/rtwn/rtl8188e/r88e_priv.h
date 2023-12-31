/*-
 * Copyright (c) 2010 Damien Bergamini <damien.bergamini@free.fr>
 * Copyright (c) 2016 Andriy Voskoboinyk <avos@FreeBSD.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $
 */

#ifndef R88E_PRIV_H
#define R88E_PRIV_H

#include <dev/rtwn/rtl8188e/r88e_rom_defs.h>

/*
 * Parsed Tx power (diff) values.
 */
struct rtwn_r88e_txpwr {
	uint8_t		cck_tx_pwr[R88E_GROUP_2G];
	uint8_t		ht40_tx_pwr[R88E_GROUP_2G - 1];
	int8_t		ofdm_tx_pwr_diff;
	int8_t		bw20_tx_pwr_diff;
};

/*
 * MAC initialization values.
 */
static const struct rtwn_mac_prog rtl8188e_mac[] = {
	{ 0x026, 0x41 }, { 0x027, 0x35 }, { 0x040, 0x00 }, { 0x428, 0x0a },
	{ 0x429, 0x10 }, { 0x430, 0x00 }, { 0x431, 0x01 }, { 0x432, 0x02 },
	{ 0x433, 0x04 }, { 0x434, 0x05 }, { 0x435, 0x06 }, { 0x436, 0x07 },
	{ 0x437, 0x08 }, { 0x438, 0x00 }, { 0x439, 0x00 }, { 0x43a, 0x01 },
	{ 0x43b, 0x02 }, { 0x43c, 0x04 }, { 0x43d, 0x05 }, { 0x43e, 0x06 },
	{ 0x43f, 0x07 }, { 0x440, 0x5d }, { 0x441, 0x01 }, { 0x442, 0x00 },
	{ 0x444, 0x15 }, { 0x445, 0xf0 }, { 0x446, 0x0f }, { 0x447, 0x00 },
	{ 0x458, 0x41 }, { 0x459, 0xa8 }, { 0x45a, 0x72 }, { 0x45b, 0xb9 },
	{ 0x460, 0x66 }, { 0x461, 0x66 }, { 0x480, 0x08 }, { 0x4c8, 0xff },
	{ 0x4c9, 0x08 }, { 0x4cc, 0xff }, { 0x4cd, 0xff }, { 0x4ce, 0x01 },
	{ 0x4d3, 0x01 }, { 0x500, 0x26 }, { 0x501, 0xa2 }, { 0x502, 0x2f },
	{ 0x503, 0x00 }, { 0x504, 0x28 }, { 0x505, 0xa3 }, { 0x506, 0x5e },
	{ 0x507, 0x00 }, { 0x508, 0x2b }, { 0x509, 0xa4 }, { 0x50a, 0x5e },
	{ 0x50b, 0x00 }, { 0x50c, 0x4f }, { 0x50d, 0xa4 }, { 0x50e, 0x00 },
	{ 0x50f, 0x00 }, { 0x512, 0x1c }, { 0x514, 0x0a }, { 0x516, 0x0a },
	{ 0x525, 0x4f }, { 0x550, 0x10 }, { 0x551, 0x10 }, { 0x559, 0x02 },
	{ 0x55d, 0xff }, { 0x605, 0x30 }, { 0x608, 0x0e }, { 0x609, 0x2a },
	{ 0x620, 0xff }, { 0x621, 0xff }, { 0x622, 0xff }, { 0x623, 0xff },
	{ 0x624, 0xff }, { 0x625, 0xff }, { 0x626, 0xff }, { 0x627, 0xff },
	{ 0x652, 0x20 }, { 0x63c, 0x0a }, { 0x63d, 0x0a }, { 0x63e, 0x0e },
	{ 0x63f, 0x0e }, { 0x640, 0x40 }, { 0x66e, 0x05 }, { 0x700, 0x21 },
	{ 0x701, 0x43 }, { 0x702, 0x65 }, { 0x703, 0x87 }, { 0x708, 0x21 },
	{ 0x709, 0x43 }, { 0x70a, 0x65 }, { 0x70b, 0x87 }
};

/*
 * Baseband initialization values.
 */
static const uint16_t rtl8188e_bb_regs[] = {
	0x800, 0x804, 0x808, 0x80c, 0x810, 0x814, 0x818, 0x81c,
	0x820, 0x824, 0x828, 0x82c, 0x830, 0x834, 0x838, 0x83c,
	0x840, 0x844, 0x848, 0x84c, 0x850, 0x854, 0x858, 0x85c,
	0x860, 0x864, 0x868, 0x86c, 0x870, 0x874, 0x878, 0x87c,
	0x880, 0x884, 0x888, 0x88c, 0x890, 0x894, 0x898, 0x89c,
	0x900, 0x904, 0x908, 0x90c, 0x910, 0x914, 0xa00, 0xa04,
	0xa08, 0xa0c, 0xa10, 0xa14, 0xa18, 0xa1c, 0xa20, 0xa24,
	0xa28, 0xa2c, 0xa70, 0xa74, 0xa78, 0xa7c, 0xa80, 0xb2c,
	0xc00, 0xc04, 0xc08, 0xc0c, 0xc10, 0xc14, 0xc18, 0xc1c,
	0xc20, 0xc24, 0xc28, 0xc2c, 0xc30, 0xc34, 0xc38, 0xc3c,
	0xc40, 0xc44, 0xc48, 0xc4c, 0xc50, 0xc54, 0xc58, 0xc5c,
	0xc60, 0xc64, 0xc68, 0xc6c, 0xc70, 0xc74, 0xc78, 0xc7c,
	0xc80, 0xc84, 0xc88, 0xc8c, 0xc90, 0xc94, 0xc98, 0xc9c,
	0xca0, 0xca4, 0xca8, 0xcac, 0xcb0, 0xcb4, 0xcb8, 0xcbc,
	0xcc0, 0xcc4, 0xcc8, 0xccc, 0xcd0, 0xcd4, 0xcd8, 0xcdc,
	0xce0, 0xce4, 0xce8, 0xcec, 0xd00, 0xd04, 0xd08, 0xd0c,
	0xd10, 0xd14, 0xd18, 0xd2c, 0xd30, 0xd34, 0xd38, 0xd3c,
	0xd40, 0xd44, 0xd48, 0xd4c, 0xd50, 0xd54, 0xd58, 0xd5c,
	0xd60, 0xd64, 0xd68, 0xd6c, 0xd70, 0xd74, 0xd78, 0xe00,
	0xe04, 0xe08, 0xe10, 0xe14, 0xe18, 0xe1c, 0xe28, 0xe30,
	0xe34, 0xe38, 0xe3c, 0xe40, 0xe44, 0xe48, 0xe4c, 0xe50,
	0xe54, 0xe58, 0xe5c, 0xe60, 0xe68, 0xe6c, 0xe70, 0xe74,
	0xe78, 0xe7c, 0xe80, 0xe84, 0xe88, 0xe8c, 0xed0, 0xed4,
	0xed8, 0xedc, 0xee0, 0xee8, 0xeec, 0xf14, 0xf4c, 0xf00
};

static const uint32_t rtl8188e_bb_vals[] = {
	0x80040000, 0x00000003, 0x0000fc00, 0x0000000a, 0x10001331,
	0x020c3d10, 0x02200385, 0x00000000, 0x01000100, 0x00390204,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00010000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x569a11a9, 0x01000014, 0x66f60110,
	0x061f0649, 0x00000000, 0x27272700, 0x07000760, 0x25004000,
	0x00000808, 0x00000000, 0xb0000c1c, 0x00000001, 0x00000000,
	0xccc000c0, 0x00000800, 0xfffffffe, 0x40302010, 0x00706050,
	0x00000000, 0x00000023, 0x00000000, 0x81121111, 0x00000002,
	0x00000201, 0x00d047c8, 0x80ff000c, 0x8c838300, 0x2e7f120f,
	0x9500bb78, 0x1114d028, 0x00881117, 0x89140f00, 0x1a1b0000,
	0x090e1317, 0x00000204, 0x00d30000, 0x101fbf00, 0x00000007,
	0x00000900, 0x225b0606, 0x218075b1, 0x80000000, 0x48071d40,
	0x03a05611, 0x000000e4, 0x6c6c6c6c, 0x08800000, 0x40000100,
	0x08800000, 0x40000100, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x69e9ac47, 0x469652af, 0x49795994, 0x0a97971c,
	0x1f7c403f, 0x000100b7, 0xec020107, 0x007f037f, 0x69553420,
	0x43bc0094, 0x00013169, 0x00250492, 0x00000000, 0x7112848b,
	0x47c00bff, 0x00000036, 0x2c7f000d, 0x020610db, 0x0000001f,
	0x00b91612, 0x390000e4, 0x20f60000, 0x40000100, 0x20200000,
	0x00091521, 0x00000000, 0x00121820, 0x00007f7f, 0x00000000,
	0x000300a0, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x28000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x64b22427, 0x00766932,
	0x00222222, 0x00000000, 0x37644302, 0x2f97d40c, 0x00000740,
	0x00020401, 0x0000907f, 0x20010201, 0xa0633333, 0x3333bc43,
	0x7a8f5b6f, 0xcc979975, 0x00000000, 0x80608000, 0x00000000,
	0x00127353, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x6437140a, 0x00000000, 0x00000282, 0x30032064, 0x4653de68,
	0x04518a3c, 0x00002101, 0x2a201c16, 0x1812362e, 0x322c2220,
	0x000e3c24, 0x2d2d2d2d, 0x2d2d2d2d, 0x0390272d, 0x2d2d2d2d,
	0x2d2d2d2d, 0x2d2d2d2d, 0x2d2d2d2d, 0x00000000, 0x1000dc1f,
	0x10008c1f, 0x02140102, 0x681604c2, 0x01007c00, 0x01004800,
	0xfb000000, 0x000028d1, 0x1000dc1f, 0x10008c1f, 0x02140102,
	0x28160d05, 0x00000008, 0x001b25a4, 0x00c00014, 0x00c00014,
	0x01000014, 0x01000014, 0x01000014, 0x01000014, 0x00c00014,
	0x01000014, 0x00c00014, 0x00c00014, 0x00c00014, 0x00c00014,
	0x00000014, 0x00000014, 0x21555448, 0x01c00014, 0x00000003,
	0x00000000, 0x00000300
};

static const struct rtwn_bb_prog rtl8188e_bb[] = {
	{
		nitems(rtl8188e_bb_regs),
		rtl8188e_bb_regs,
		rtl8188e_bb_vals,
		{ 0 },
		NULL
	}
};

static const uint32_t rtl8188e_agc_vals[] = {
	0xfb000001, 0xfb010001, 0xfb020001, 0xfb030001, 0xfb040001,
	0xfb050001, 0xfa060001, 0xf9070001, 0xf8080001, 0xf7090001,
	0xf60a0001, 0xf50b0001, 0xf40c0001, 0xf30d0001, 0xf20e0001,
	0xf10f0001, 0xf0100001, 0xef110001, 0xee120001, 0xed130001,
	0xec140001, 0xeb150001, 0xea160001, 0xe9170001, 0xe8180001,
	0xe7190001, 0xe61a0001, 0xe51b0001, 0xe41c0001, 0xe31d0001,
	0xe21e0001, 0xe11f0001, 0x8a200001, 0x89210001, 0x88220001,
	0x87230001, 0x86240001, 0x85250001, 0x84260001, 0x83270001,
	0x82280001, 0x6b290001, 0x6a2a0001, 0x692b0001, 0x682c0001,
	0x672d0001, 0x662e0001, 0x652f0001, 0x64300001, 0x63310001,
	0x62320001, 0x61330001, 0x46340001, 0x45350001, 0x44360001,
	0x43370001, 0x42380001, 0x41390001, 0x403a0001, 0x403b0001,
	0x403c0001, 0x403d0001, 0x403e0001, 0x403f0001, 0xfb400001,
	0xfb410001, 0xfb420001, 0xfb430001, 0xfb440001, 0xfb450001,
	0xfb460001, 0xfb470001, 0xfb480001, 0xfa490001, 0xf94a0001,
	0xf84B0001, 0xf74c0001, 0xf64d0001, 0xf54e0001, 0xf44f0001,
	0xf3500001, 0xf2510001, 0xf1520001, 0xf0530001, 0xef540001,
	0xee550001, 0xed560001, 0xec570001, 0xeb580001, 0xea590001,
	0xe95a0001, 0xe85b0001, 0xe75c0001, 0xe65d0001, 0xe55e0001,
	0xe45f0001, 0xe3600001, 0xe2610001, 0xc3620001, 0xc2630001,
	0xc1640001, 0x8b650001, 0x8a660001, 0x89670001, 0x88680001,
	0x87690001, 0x866a0001, 0x856b0001, 0x846c0001, 0x676d0001,
	0x666e0001, 0x656f0001, 0x64700001, 0x63710001, 0x62720001,
	0x61730001, 0x60740001, 0x46750001, 0x45760001, 0x44770001,
	0x43780001, 0x42790001, 0x417a0001, 0x407b0001, 0x407c0001,
	0x407d0001, 0x407e0001, 0x407f0001
};

static const struct rtwn_agc_prog rtl8188e_agc[] = {
	{
		nitems(rtl8188e_agc_vals),
		rtl8188e_agc_vals,
		{ 0 },
		NULL
	}
};

/*
 * RF initialization values.
 */
static const uint8_t rtl8188e_rf_regs[] = {
	0x00, 0x08, 0x18, 0x19, 0x1e, 0x1f, 0x2f, 0x3f, 0x42, 0x57,
	0x58, 0x67, 0x83, 0xb0, 0xb1, 0xb2, 0xb4, 0xb6, 0xb7, 0xb8,
	0xb9, 0xba, 0xbb, 0xbf, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
	0xc8, 0xc9, 0xca, 0xdf, 0xef, 0x51, 0x52, 0x53, 0x56,
	0x35, 0x35, 0x35, 0x36, 0x36, 0x36, 0x36, 0xb6, 0x18, 0x5a,
	0x19, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34,
	0x34, 0x34, 0x00, 0x84, 0x86, 0x87, 0x8e, 0x8f, 0xef, 0x3b,
	0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b,
	0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0xef, 0x00, 0x18, 0xfe, 0xfe,
	0x1f, 0xfe, 0xfe, 0x1e, 0x1f, 0x00
};

static const uint32_t rtl8188e_rf_vals[] = {
	0x30000, 0x84000, 0x00407, 0x00012, 0x80009, 0x00880, 0x1a060,
	0x00000, 0x060c0, 0xd0000, 0xbe180, 0x01552, 0x00000, 0xff8fc,
	0x54400, 0xccc19, 0x43003, 0x4953e, 0x1c718, 0x060ff, 0x80001,
	0x40000, 0x00400, 0xc0000, 0x02400, 0x00009, 0x40c91, 0x99999,
	0x000a3, 0x88820, 0x76c06, 0x00000, 0x80000, 0x00180, 0x001a0,
	0x6b27d, 0x7e49d, 0x00073, 0x51ff3, 0x00086, 0x00186,
	0x00286, 0x01c25, 0x09c25, 0x11c25, 0x19c25, 0x48538, 0x00c07,
	0x4bd00, 0x739d0, 0x0adf3, 0x09df0, 0x08ded, 0x07dea, 0x06de7,
	0x054ee, 0x044eb, 0x034e8, 0x0246b, 0x01468, 0x0006d, 0x30159,
	0x68200, 0x000ce, 0x48a00, 0x65540, 0x88000, 0x020a0, 0xf02b0,
	0xef7b0, 0xd4fb0, 0xcf060, 0xb0090, 0xa0080, 0x90080, 0x8f780,
	0x722b0, 0x6f7b0, 0x54fb0, 0x4f060, 0x30090, 0x20080, 0x10080,
	0x0f780, 0x000a0, 0x10159, 0x0f407, 0x0c350, 0x0c350, 0x80003,
	0x0c350, 0x0c350, 0x00001, 0x80000, 0x33e60
};

static const struct rtwn_rf_prog rtl8188e_rf[] = {
	{
		nitems(rtl8188e_rf_regs),
		rtl8188e_rf_regs,
		rtl8188e_rf_vals,
		{ 0 },
		NULL
	},
	{ 0, NULL, NULL, { 0 }, NULL }
};

#endif	/* R88E_PRIV_H */
