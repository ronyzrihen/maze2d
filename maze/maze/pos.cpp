
#include "pos.h"

ostream& operator<<(ostream& out, pos& source) {
	source.print(out);
	return out;
}
