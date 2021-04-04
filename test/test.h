/**
 * @file test.h
 * @author Nyk Cowham (nyk@cowham.net)
 * @brief Test suite to test the libbitopt header-only library macros
 * @version 0.1
 * @date 2021-04-04
 * 
 * @copyright Creative Commons Zero v1.0 Universal
 * 
 */
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../lib/bitoption.h"

/**
 * @brief Custom bit field masks for options equivalent to BIT_OPT(OFFSET) macro
 * 
 * Since we are testing the BIT_OPT(OFFSET) macro itself in this test, 
 * we set these using bitwise left shift expressions directly.
 */
#define BIT_1 1         ///< BIT_OPT_MASK(0) = 1      == 0x01 == 0b00000001
#define BIT_2 1 << 1    ///< BIT_OPT_MASK(1) = 1 << 1 == 0x02 == 0b00000010
#define BIT_3 1 << 2    ///< BIT_OPT_MASK(2) = 1 << 2 == 0x04 == 0b00000100
#define BIT_4 1 << 3    ///< BIT_OPT_MASK(3) = 1 << 3 == 0x08 == 0b00001000
#define BIT_5 1 << 4    ///< BIT_OPT_MASK(4) = 1 << 4 == 0x10 == 0b00010000
#define BIT_6 1 << 5    ///< BIT_OPT_MASK(5) = 1 << 5 == 0x20 == 0b00100000
#define BIT_7 1 << 6    ///< BIT_OPT_MASK(6) = 1 << 6 == 0x40 == 0b01000000
#define BIT_8 1 << 7    ///< BIT_OPT_MASK(7) = 1 << 7 == 0x80 == 0b10000000

/**
 * @brief Test BIT_OPT_MASK(POSITION) macro
 * 
 * @param offset the bit position to select for the option
 * @param expect the expected value the entire byte/s
 * @return result of the BIT_OPT_MASK() operation
 */
uint8_t can_set_option(size_t offset, uint8_t expect);

/**
 * @brief Test the BIT_OPT_ON(FIELD, MASK) macro
 * 
 * @param bitfield the base bit field to be modifed
 * @param option the bit mask to enable the option (set to 1)
 * @param expect the expected value of the bit field
 * @return the modified bit field
 */
uint8_t can_enable_option(uint8_t bitfield, uint8_t mask, uint8_t expect);

/**
 * @brief Test the BIT_OPT_OFF(FIELD, MASK) macro
 * 
 * @param bitfield the base bit field to be modified
 * @param mask the bit mask to disable the option (set to 0)
 * @param expect the expected value of the bit field
 * @return the modified bit field
 */
uint8_t can_disable_option(uint8_t bitfield, uint8_t option, uint8_t expect);

/**
 * @brief Test the BIT_OPT_TOGGLE(FIELD, MASK) macro
 * 
 * @param bitfield the base bit field to be modified
 * @param mask the bit mask to toggle the option
 * @param expect the expected value of the bit field after toggling
 * @return the modified bit field
 */
uint8_t can_toggle_option(uint8_t bitfield, uint8_t mask, uint8_t expect);

/**
 * @brief Test the BIT_OPT_CHECK(FIELD, MASK) macro
 * 
 * @param bitfield the base bit field to be checked
 * @param mask the bit mask of the field to check
 * @param expect the expected truth value of the check
 * @return true if the bit is enabled (bit is set to 1)
 * @return false if the bit is not enabled (bit is set to 0)
 */
bool option_is_enabled(uint8_t bitfield, uint8_t mask, bool expect);
