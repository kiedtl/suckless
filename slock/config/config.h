/* user and group to drop privileges to */
static const char *user  = "kiedtl";
static const char *group = "kiedtl";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#080808",   /* after initialization */
	[INPUT] =  "#0A96FF",   /* during input */
	[FAILED] = "#FF0A0A",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;
