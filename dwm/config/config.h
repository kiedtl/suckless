static unsigned int gappx = 41;
static const unsigned int borderpx  = 0;
static const int showbar            = 1;
static const int topbar             = 1;
static const int bh = 0; // bar height
static const int focusonwheel = 1;

//static const char *colors[][3]      = {
//    /*               fg         bg         border   */
//    [SchemeNorm] = { "#bbbbbb", "#222222", "#555555" },
//    [SchemeSel]  = { "#eeeeee", "#eeeeee", "#333333" },
//    [SchemeUrg]  = { "#ff0000", "#ff0000", "#ff0000" },
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
static const char norm_border[] = "#8d8e8d";

static const char sel_fg[] = "#cacbca";
static const char sel_bg[] = "#4B5451";
static const char sel_border[] = "#cacbca";

/* end my colors */
static const char *colors[][3]      = {
	[SchemeNorm] = { col_norm_fg, col_norm_bg, col_norm_bdr },
	[SchemeSel]  = { col_sel_fg, col_sel_bg,  col_sel_bdr },
	[SchemeUrg]  = { col_sel_fg, col_sel_bg,  col_sel_bdr },
};


static const int NUM_WORKSPACES=9;
static const char *tags[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8" };

static const Rule rules[] = {
    /* class      instance    title                 tags mask  iscentered   isfloating   monitor */
    { "Gimp",     NULL,       "Gimp",                 0,         0,           1,           -1 },
    { "Image Manipulation Program", NULL, "Image Manipulation Program",  0, 0, 1, -1 },
    { "GNU Image Manipulation Program", NULL, "GNU Image Manipulation Program", 0, 0, 1, -1 },
    { "st",              NULL,       "surf-download",     0,         1,           1,           -1 },
    { "surf-download",   NULL,       "surf-download",     0,         1,           1,           -1 },
    { "floating-st",     NULL,       "floating-st",       0,         1,           1,           -1 },
    { "tabbed",          NULL,       "floating-st",       0,         1,           1,           -1 },
    { "st",              NULL,       "floating-st",       0,         1,           1,           -1 },
    { "st",              NULL,       "x9term",            0,         1,           1,           -1 },
    { "0",               NULL,       "x9term",            0,         1,           1,           -1 },
    { "NULL",            NULL,       "x9term",            0,         1,           1,           -1 },
    { "feh",             NULL,       "feh",               0,         1,           1,           -1 },
    { "meh",             NULL,       "meh",               0,         1,           1,           -1 },
    { "mpv",             NULL,       "mpv",               0,         1,           1,           -1 },
    { "x9term",          NULL,       "x9term",            0,         0,           1,           -1 },
};

static const float mfact     = 0.5;
static const int nmaster     = 1;
static const int resizehints = 1;

static const int NUM_LAYOUTS = 3;
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "T",      tile },    /* first entry is default */
    { "F",      NULL },    /* no layout function means floating behavior */
    { "M",      monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) { MODKEY, KEY, view, {.ui = 1 << TAG} }, \
                         { MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", "xos4 Terminus:size=11", "-nb", col_norm_bg, "-nf", col_norm_fg, "-sb", col_sel_bg, "-sf", col_sel_fg, NULL };
static const char *termcmd[]  = { "urxvt", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "urxvt", "-tn", scratchpadname, "-geometry", "84x24", NULL };
 
static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_d,      spawn,          {.v = dmenucmd }  },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd }  },
    { MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  togglescratch,  {.v = scratchpadcmd } },
    { MODKEY,                       XK_s,      togglesticky,   {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_h,      rotatestack,    {.i = -1 } },
    { MODKEY,                       XK_l,      rotatestack,    {.i = +1 } },
    { MODKEY,                       XK_Tab,    view,           {0} },
    TAGKEYS(XK_1,0) TAGKEYS(XK_2,1) TAGKEYS(XK_3,2) TAGKEYS(XK_4,3) TAGKEYS(XK_5,4)
    TAGKEYS(XK_6,5) TAGKEYS(XK_7,6) TAGKEYS(XK_8,7) TAGKEYS(XK_9,8) TAGKEYS(XK_0,9)
    TAGKEYS(XK_parenleft,10) TAGKEYS(XK_parenright,11) TAGKEYS(XK_BackSpace,12)
    { MODKEY|ShiftMask,             XK_e,      quit,           {0} },
};

static Button buttons[] = {
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkRootWin,           0,              Button3,        spawn,          SHCMD("x9term") },
};
