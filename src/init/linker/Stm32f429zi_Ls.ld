/*!
 * $File: Stm32f429zi_Ls.ld
 * $Revision: Version 1.1 (C++ enabled) $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 *
 * Soporte C++:
 *  - .preinit_array / .init_array / .fini_array
 *  - .ctors / .dtors legacy (por compatibilidad)
 *  - Tablas de unwind (.ARM.exidx / .ARM.extab) si no desactivas excepciones
 */

ENTRY(Reset_Handler)

/* MEMORIA (ajusta si usas capacidad completa del MCU) */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K 
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 112K 
}

/* Top de stack */
_estack = ORIGIN(SRAM) + LENGTH(SRAM);

/* Tamaños mínimos (para mapa / chequeo) */
__max_heap_size  = 0x200;  /* 512 B */
__max_stack_size = 0x400;  /* 1 KB */

/* SECCIONES */
SECTIONS
{
    /* Vector de interrupciones separado para claridad */
    .isr_vector_table :
    {
        . = ALIGN(128);
        KEEP(*(.isr_vector_table))
        . = ALIGN(4);
    } > FLASH

    /* Código y datos de solo lectura */
    .text :
    {
        . = ALIGN(4);
        _stext = .;
        __text_start__ = _stext;

        /* Código */
        *(.text.startup .text.startup.*)
        *(.text .text.*)
        *(.ramfunc.load) /* Imagen FLASH de funciones que irán a RAM */

        /* Código de inicialización / finalización (legacy) */
        *(.init)
        *(.fini)

        /* Tablas de excepción (si usas excepciones C++) */
        *(.gcc_except_table)
        *(.gnu.linkonce.t.*)

        /* Read Only Data */
        *(.rodata .rodata.* .gnu.linkonce.r.*)

        /* Soporte C++ moderno */
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP(*(.preinit_array*))
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array*))
        __init_array_end = .;

        . = ALIGN(4);
        __fini_array_start = .;
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array*))
        __fini_array_end = .;

        /* Legacy constructors/destructors (solo si alguna toolchain antigua los emite) */
        . = ALIGN(4);
        __ctors_start__ = .;
        KEEP(*(.ctors))
        KEEP(*(.ctors.*))
        __ctors_end__ = .;

        . = ALIGN(4);
        __dtors_start__ = .;
        KEEP(*(.dtors))
        KEEP(*(.dtors.*))
        __dtors_end__ = .;

        . = ALIGN(4);
        __text_end__ = .;
    } > FLASH

    /* Tablas de unwind (necesarias solo si NO compilas con -fno-exceptions -fno-unwind-tables) */
    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    .ARM.exidx :
    {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > FLASH

    /* Imagen de .data en FLASH (LMA) */
    _etext = LOADADDR(.data);

    /* Datos inicializados (se copian a RAM) */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        __data_start__ = _sdata;

        *(.data .data.* .gnu.linkonce.d.*)
        *(.ramfunc .ramfunc.*)  /* Código a ejecutar en RAM (opcional) */

        . = ALIGN(4);
        _edata = .;
        __data_end__ = _edata;
    } > SRAM AT > FLASH

    /* Ejemplo: funciones en RAM dedicadas (si separas) 
    .ramfunc :
    {
        . = ALIGN(4);
        _sramfunc = .;
        *(.fastcode*)
        . = ALIGN(4);
        _eramfunc = .;
    } > SRAM AT > FLASH
    */

    /* Datos no inicializados conservados (no se limpian) */
    .noinit (NOLOAD) :
    {
        . = ALIGN(4);
        _snoinit = .;
        *(.noinit .noinit.*)
        . = ALIGN(4);
        _enoinit = .;
    } > SRAM

    /* BSS */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = .;
        __bss_start__ = _sbss;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss;
        __end__ = .;
        end = .;
    } > SRAM

    /* Heap y Stack (espacio reservado opcional, facilita análisis de overflow) */
    ._heap_stack (NOLOAD):
    {
        . = ALIGN(8);
        __heap_start__ = .;
        . += __max_heap_size;
        __heap_end__ = .;
        . = ALIGN(8);
        __stack_bottom__ = .;
        . += __max_stack_size;
        __stack_top__ = .;
    } > SRAM

    /* Símbolo genérico de final */
    _end = .;
}

/* Proveer alias usados por librerías */
PROVIDE(end = _end);
PROVIDE(__end__ = _end);
PROVIDE(__HeapBase = __heap_start__);
PROVIDE(__HeapLimit = __heap_end__);
PROVIDE(__StackLimit = __stack_bottom__);
PROVIDE(__StackTop = _estack);

/* Si desactivas excepciones (-fno-exceptions -fno-unwind-tables) puedes eliminar .ARM.extab / .ARM.exidx arriba */