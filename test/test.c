#include "test.h"

int main() {

    printf("*** Testing BIT_OPT(OFFSET) macro ***\n");
    can_set_option(0, BIT_1);
    can_set_option(1, BIT_2);
    can_set_option(2, BIT_3);
    can_set_option(3, BIT_4);
    can_set_option(4, BIT_5);
    can_set_option(5, BIT_6);
    can_set_option(6, BIT_7);
    can_set_option(7, BIT_8);

    uint8_t field;
    printf("\n*** Testing BIT_OPT_ON(FIELD, MASK) macro ***\n");
    field = can_enable_option(0x00, BIT_1, 0b0001);
    field = can_enable_option(field, BIT_2, 0b0011);
    field = can_enable_option(field, BIT_3, 0b0111);
    field = can_enable_option(field, BIT_4, 0b1111);
    can_enable_option(0x00, BIT_1 | BIT_3, 0b0101);

    printf("\n*** Testing BIT_OPT_OFF(FIELD, MASK) macro ***\n");
    field = can_disable_option(0x0F, BIT_1, 0b1110);
    field = can_disable_option(field, BIT_2, 0b1100);
    field = can_disable_option(field, BIT_3, 0b1000);
    field = can_disable_option(field, BIT_4, 0b0000);
    can_disable_option(0x0F, BIT_1 | BIT_3, 0b1010);

    printf("\n*** Testing BIT_OPT_TOGGLE(FIELD, MASK) macro ***\n");
    field = can_toggle_option(0x00, BIT_2, 0b0010);
    field = can_toggle_option(field, BIT_2, 0b0000);
    field = can_toggle_option(field, BIT_1 | BIT_3, 0b0101);
    can_toggle_option(field, BIT_3 | BIT_1, 0b0000);
    
    printf("\n*** Testing BIT_OPT_ENABLED(FIELD, MASK) macro ***\n");
    option_is_enabled(0b1100, BIT_4, true);
    option_is_enabled(0b1100, BIT_3, true);
    option_is_enabled(0b1100, BIT_2, false);
    option_is_enabled(0b1100, BIT_1, false);

    printf("\nAll tests passed!\n");
    return EXIT_SUCCESS;    
}

uint8_t can_set_option(size_t offset, uint8_t expect) {
    uint8_t result = BIT_OPT_MASK(offset);
    printf("Running test: can_set_option(number = %d, expect = %d)\n", (int)offset, expect);
    assert(result == expect);
    return result;
}

uint8_t can_enable_option(uint8_t bitfield, uint8_t mask, uint8_t expect) {
    uint8_t field = BIT_OPT_ON(bitfield, mask);
    printf("Running test: can_enable_option(field = %d, mask = %d, expect = %d)\n", bitfield, mask, expect);
    assert(field == expect && "Expected and given values for BIT_OPT_ON failed!\n");
    return field;
}

uint8_t can_disable_option(uint8_t bitfield, uint8_t mask, uint8_t expect) {
    uint8_t field = BIT_OPT_OFF(bitfield, mask);
    printf("Running test: can_disable_option(field = %d, mask = %d, expect = %d)\n", bitfield, mask, expect);
    assert(field == expect && "Expected and given values for BIT_OPT_OFF failed!\n");
    return field;
}

uint8_t can_toggle_option(uint8_t bitfield, uint8_t mask, uint8_t expect) {
    uint8_t field = BIT_OPT_TOGGLE(bitfield, mask);
    printf("Running test: can_toggle_option(field = %d, mask = %d, expect = %d\n", bitfield, mask, expect);
    assert(field == expect && "Expected and give values for BIT_OPT_TOGGLE failed!\n");
    return field;
}

bool option_is_enabled(uint8_t bitfield, uint8_t mask, bool expect) {
    bool t = BIT_OPT_CHECK(bitfield, mask);
    printf("Running test: option_enabled(ield = %d, mask = %d, expect = %d)\n", bitfield, mask, expect);
    assert(t == expect && "Expected and given values for BIT_OPT_ENABLED failed!\n");
    return t;
}
