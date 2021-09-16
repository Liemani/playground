int main()
{
#if defined(AIRPLANE)
	"I'm boarding airplane";
#elif defined(BIKE)
	"I'm riding bike";
#else
	"I'm just walking";
#endif
	return (0);
}
