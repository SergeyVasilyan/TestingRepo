#include"/***/***/project.hpp"
#include<iostream>

int main()
{
	project pro;
	pro.get();
	property_box_specification pro_spec1;
	property_box_specification pro_spec2;
        pro_spec1 = pro.add_property_box_specification("a_00");
	pro_spec2 = pro.add_property_box_specification("a_01");
	pro_spec1.set_description() = "*****";
	pro_spec1.set_shape() = "rectangle";
	//dzevy tal;
	assert(pro_spec1 == get_property_box_specification("a_00"));
	assert(pro_spec1.get_description() == "*****");
	//...
	property_box pro_b1;
        property_box pro_b2;
	pro_b1 = pro.add_property_box("p_00", pro_spec1);
	pro_b2 = pro.add_property_box("p_01", pro_spec2);
	pro_b1.set_width() = 30;
	pro_b1.set_height() = 10;
	//....
	assert(pro_b1 == get_property_box("p_00"));
	//myus assertnery
	//propertiyov petqa arjecnery lcnem property_specification-neri




	return 0;
}
