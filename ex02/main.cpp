
#include "includes/Base.hpp"

int	main()
{
	Base* bp = generate();
	Base* cp = generate();
	Base* ap = generate();
	Base* dp = NULL;
	A ar;
	B br;
	C cr;

	identify(bp);
	identify(cp);
	identify(ap);
	identify(dp);

	identify(ar);
	identify(br);
	identify(cr);

	delete ap;
	delete bp;
	delete cp;
	delete dp;

	return 0;
}