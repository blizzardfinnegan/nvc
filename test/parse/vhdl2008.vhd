--
-- Grab bag of miscellaneous VHDL-2008 syntax
--

entity vhdl2008 is
end entity;

architecture test of vhdl2008 is

    type my_utype is (a, b, c);
    type my_utype_vector is array (natural range <>) of my_utype;

    function resolved (s : my_utype_vector) return my_utype;

    subtype my_type is resolved my_utype;
    subtype my_type_vector is (resolved) my_utype_vector;  -- OK

    type my_logical_vec is array (natural range <>) of bit;
begin

    process is
        variable b : bit;
        variable v : my_logical_vec(1 to 3);
    begin
        b := or v;                      -- OK
        if or v = '1' then end if;      -- OK
        b := and v;                     -- OK
        b := xor v;                     -- OK
        b := xnor v;                    -- OK
        b := nand v;                    -- OK
        b := nor v;                     -- OK
    end process;

end architecture;
