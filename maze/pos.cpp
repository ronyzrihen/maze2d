
#include "pos.h"

string pos::get_position() const{
    string position;
    std::ostringstream ss;
    ss << row << " , " << col;
    return ss.str();
}


ostream& operator<<(ostream& out, pos& source) {
	source.print(out);
	return out;
}
