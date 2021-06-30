#include "/***/***/project.hpp"
#include <cassert>

int main()
{
	using project = nisseki::puente::db::project;
	project& pro = project::get();
	property_box_specification *pro_b_spec1;
	*pro_b_spec1 = pro.add_property_box_specification("IfcFooting");
	pro_b_spec1->set_name("Foundation Symbol");
	pro_b_spec1-set_description("Description of the Foundation Symbol");
	pro_b_spec1.set_shape("rectangle");
	property_specification *pro_b1 = pro_b_spec1.add_property("Name");
	pro_b1.set_description("Object Name");
	pro_b1.set_cell(0,0);
	pro_b1.set_row_span(2);
	pro_b1.set_column_span(1);




	assert(pro_b_spec1 == get_property_box_specification("a_00"));
	assert(pro_b_spec1.get_description() == "*****");
	//...
	
	property_box *pro_b1;
	*pro_b1 = pro.add_property_box("p_00", pro_b_spec1);
	pro_b1.set_width() = 30;
	pro_b1.set_height() = 10;
	//....
	assert(pro_b1 == get_property_box("p_00"));
	//myus assertnery
	//propertiyov petqa arjecnery lcnem property_specification-neri




	return 0;
}
