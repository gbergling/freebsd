/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2019 Emmanuel Vadot <manu@FreeBSD.Org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 *
 */

#ifndef _DWC3_H_
#define	_DWC3_H_

#define	DWC3_GSBUSCFG0		0xc100
#define	DWC3_GSBUSCFG1		0xc104
#define	DWC3_GTXTHRCFG		0xc108
#define	DWC3_GRXTHRCFG		0xc10C

/* Global Core Control Register */
#define	DWC3_GCTL			0xc110
#define	 DWC3_GCTL_PRTCAPDIR_MASK	(0x3 << 12)
#define	 DWC3_GCTL_PRTCAPDIR_HOST	(0x1 << 12)
#define	 DWC3_GCTL_PRTCAPDIR_DEVICE	(0x2 << 12)
#define	 DWC3_GCTL_CORESOFTRESET	(1 << 11)
#define	 DWC3_GCTL_DSBLCLKGTNG		(1 << 0)

#define	DWC3_GPMSTS		0xc114
#define	DWC3_GSTS		0xc118

#define	DWC3_GUCTL1		0xc11c
#define	 DWC3_GUCTL1_TX_IPGAP_LINECHECK_DIS	(1 << 28)

#define	DWC3_GSNPSID		0xc120
#define	DWC3_GGPIO		0xc124
#define	DWC3_GUID		0xc128
#define	DWC3_GUCTL		0xc12C
#define	DWC3_GBUSERRADDRLO	0xc130
#define	DWC3_GBUSERRADDRHI	0xc134
#define	DWC3_GPRTBIMAPLO	0xc138
#define	DWC3_GHWPARAMS0		0xc140
#define	DWC3_GHWPARAMS1		0xc144
#define	DWC3_GHWPARAMS2		0xc148
#define	DWC3_GHWPARAMS3		0xc14C
#define	DWC3_GHWPARAMS4		0xc150
#define	DWC3_GHWPARAMS5		0xc154
#define	DWC3_GHWPARAMS6		0xc158
#define	DWC3_GHWPARAMS7		0xc15C
#define	DWC3_GDBGFIFOSPACE	0xc160
#define	DWC3_GDBGLTSSM		0xc164
#define	DWC3_GDBGLNMCC		0xc168
#define	DWC3_GDBGBMU		0xc16C
#define	DWC3_GDBGLSPMUX		0xc170
#define	DWC3_GDBGLSP		0xc174
#define	DWC3_GDBGEPINFO0	0xc178
#define	DWC3_GDBGEPINFO1	0xc17C
#define	DWC3_GPRTBIMAP_HSLO	0xc180
#define	DWC3_GPRTBIMAP_FSLO	0xc188

#define	DWC3_GUSB2PHYCFG0	0xc200
#define	 DWC3_GUSB2PHYCFG0_PHYSOFTRST		(1 << 31)
#define	 DWC3_GUSB2PHYCFG0_U2_FREECLK_EXISTS	(1 << 30)
#define	 DWC3_GUSB2PHYCFG0_USBTRDTIM(n)		((n) << 10)
#define	 DWC3_GUSB2PHYCFG0_USBTRDTIM_8BITS	9
#define	 DWC3_GUSB2PHYCFG0_USBTRDTIM_16BITS	5
#define	 DWC3_GUSB2PHYCFG0_ENBLSLPM		(1 << 8)
#define	 DWC3_GUSB2PHYCFG0_PHYSEL(x)		((x >> 7) & 0x1)	/* 0 = USB2.0, 1 = USB1.1 */
#define	 DWC3_GUSB2PHYCFG0_SUSPENDUSB20		(1 << 6)
#define	 DWC3_GUSB2PHYCFG0_ULPI_UTMI_SEL	(1 << 4)
#define	 DWC3_GUSB2PHYCFG0_PHYIF		(1 << 3)

#define	DWC3_GUSB3PIPECTL0			0xc2c0
#define	 DWC3_GUSB3PIPECTL0_PHYSOFTRST		(1 << 31)
#define	 DWC3_GUSB3PIPECTL0_DELAYP1TRANS	(1 << 18)

#define	DWC3_GTXFIFOSIZ(x)	(0xc300 + 0x4 * (x))
#define	DWC3_GRXFIFOSIZ(x)	(0xc380 + 0x4 * (x))
#define	DWC3_GEVNTADRLO0		0xc400
#define	DWC3_GEVNTADRHI0		0xc404
#define	DWC3_GEVNTSIZ0		0xc408
#define	DWC3_GEVNTCOUNT0		0xc40C
#define	DWC3_GHWPARAMS8		0xc600
#define	DWC3_GTXFIFOPRIDEV	0xc610
#define	DWC3_GTXFIFOPRIHST	0xc618
#define	DWC3_GRXFIFOPRIHST	0xc61c
#define	DWC3_GFIFOPRIDBC	0xc620
#define	DWC3_GDMAHLRATIO	0xc624
#define	DWC3_GFLADJ		0xc630
#define	DWC3_DCFG		0xc700
#define	DWC3_DCTL		0xc704
#define	DWC3_DEVTEN		0xc708
#define	DWC3_DSTS		0xc70C
#define	DWC3_DGCMDPAR		0xc710
#define	DWC3_DGCMD		0xc714
#define	DWC3_DALEPENA		0xc720

#endif /* _DWC3_H_ */
