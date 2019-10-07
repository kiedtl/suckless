static int topbar = 1;  /* -b  option; if 0, dmenu appears at bottom     */

static const char *fonts[] = {
    /* "Share Tech Mono:pixelsize=16:antialias=true:autohint=true" */
    /* "Share Tech Mono:pixelsize=14:antialias=true:autohint=true" */
    /* "IBMPlexMono:pixelsize=16:antialias=true:autohint=true" */
    //"IBMPlexMono:pixelsize=14:antialias=true:autohint=true"
    /* "Terminus:pixelsize=16:antialias=false:autohint=false" */
    "xos4 Terminus:pixelsize=14"
};

static const char *prompt = NULL;  /* -p  option; prompt to the left of input field */
static int fuzzy = 1; /* -F  option; if 0, dmenu doesn't use fuzzy matching */

//static const char *colors[SchemeLast][2] = {
//            	/*     fg         bg       */
//	[SchemeNorm] = { "#bbbbbb", "#373B41" },
//	[SchemeSel] =  { "#eeeeee", "#5F819D" },
//	[SchemeOut] =  { "#000000", "#00ffff" },
//};

/* my colors */
static const char col_norm_fg[]     = "#cacbca";
static const char col_norm_bg[]     = "#030f11";
static const char col_sel_fg[]      = "#cacbca";

static const char col_sel_bg[]      = "#030f11";
static const char col_norm_bdr[]    = "#8d8e8d";
static const char col_sel_bdr[]     = "#cacbca";

static const char norm_fg[] = "#cacbca";
static const char norm_bg[] = "#030F11";
static const char norm_border[] = "#cacbca";

static const char sel_fg[] = "#cacbca";
static const char sel_bg[] = "#4B5451";
static const char sel_border[] = "#cacbca";

/* end my colors */
static const char *colors[SchemeLast][2] = {
	[SchemeNorm] = { col_norm_fg, col_norm_bg },
	[SchemeSel]  = { col_sel_fg, col_sel_bg   },
	[SchemeOut]  = { "#000000", "#00ffff"     },
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/* Characters not considered part of a word while deleting words
 * for example: " /?\"&[]" */
static const char worddelimiters[] = " /?\"&[].:,";

/* Size of the window border */
static const unsigned int border_width = 4;
