/**
 * @file bitoption.h
 * @author Nyk Cowham (nyk@cowham.net)
 * @brief A zero-cost, header-only abstraction library to manipulate any number of generic bit fields
 * @version 0.1
 * @date 2021-04-04
 * 
 * @copyright Creative Commons Zero v1.0 Universal
 * 
 */
#ifndef _BIT_OPTION_LIB
#define _BIT_OPTION_LIB

/**
 * @brief Create a bit mask with a specific bit offset for use in other macros
 * 
 */
#define BIT_OPT_MASK(OFFSET) 1 << OFFSET

/**
 * @brief Enable one or more bits on a bit field using a bit mask (set bit to 1)
 * 
 */
#define BIT_OPT_ON(FIELD, MASK) (FIELD) | (MASK)

/**
 * @brief Disable one or more bits on a bit field using a bit mask (set bit to 0)
 * 
 */
#define BIT_OPT_OFF(FIELD, MASK) (FIELD) & ~(MASK)

/**
 * @brief Check to see if one or more bits in a bit field are enabled using a bit mask
 * 
 */
#define BIT_OPT_CHECK(FIELD, MASK) (FIELD) & (MASK)

/**
 * @brief Toggle one or more bits in a bit field using a bit mask
 * 
 */
#define BIT_OPT_TOGGLE(FIELD, MASK) (FIELD) ^ (MASK)

#endif // _BIT_OPTION_LIB