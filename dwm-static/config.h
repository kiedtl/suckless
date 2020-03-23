/*
 *
 * as you may have noticed, I'm one of those maniacs
 * who likes to align everything :P
 *
*/

#include "fibonacci.c"

static       unsigned int gappx        = 24;
static const unsigned int borderpx     = 0;
static const int          showbar      = 1;
static const int          topbar       = 1;
static       int          bh           = 32; // bar height
static const int          horizpadbar  = 2;
static const int          vertpadbar   = 0;
static const char         *fonts[]     = { "cozette" };

static const char         background[] = "#0d1820";
static const char         foreground[] = "#d3dadb";

static const char *colors[][3]      = {
    /*               fg          bg          border   */
    [SchemeNorm] = { foreground, background, background }, /* no border for unfocused windows */
    [SchemeSel]  = { foreground, background, foreground }, /* focused window */
    [SchemeUrg]  = { foreground, background, "#2d4e42"  },
};

static const int NUM_WORKSPACES = 8;
static const char *tags[] = { "000", "001", "010", "011", "100", "101", "110", "111" };

static const Rule rules[] = {
    /* class      instance    title                 tags mask  iscentered   isfloating   monitor */
    { "feh",             NULL,       "feh",               0,         1,           1,           -1 },
    { "xclock",          NULL,       NULL,                0,         1,           1,           -1 },
};

static const float mfact       = 0.5; /* factor of master artea size [0.05..0.95] */
static const int   nmaster     = 1;   /* number of clients in master area */
static const int   resizehints = 1;   /* 1 = respect size hints in tiles resizals */

static const int NUM_LAYOUTS = 3;
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* NULL arrange function = floating */
    { "[M]",      monocle },
    { "(@)",      spiral },
    { "[\\]",     dwindle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) { MODKEY, KEY, view, {.ui = 1 << TAG} }, \
                         { MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char scratchpadname[]  = "scratchpad";
static const char *scratchpadcmd[] = { "xterm", "-title", scratchpadname, "-geometry", "84x24", NULL };

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,      spawn,          SHCMD("ndmen") },
    { MODKEY,                       XK_Return, spawn,          SHCMD("xterm") },
    { MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("slock") },
    { MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_d,      setlayout,      {.v = &layouts[4]} },
    { MODKEY|ShiftMask,             XK_d,      setlayout,      {.v = &layouts[3]} },
    { MODKEY,                       XK_space,  togglescratch,  {.v = scratchpadcmd } },
    { MODKEY,                       XK_s,      togglesticky,   {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_h,      rotatestack,    {.i = -1 } },
    { MODKEY,                       XK_l,      rotatestack,    {.i = +1 } },
    { MODKEY,                       XK_Tab,    view,           {0} },
    TAGKEYS(XK_1,0) TAGKEYS(XK_2,1) TAGKEYS(XK_3,2) TAGKEYS(XK_4,3) TAGKEYS(XK_5,4)
    TAGKEYS(XK_6,5) TAGKEYS(XK_7,6) TAGKEYS(XK_8,7) TAGKEYS(XK_9,8)
    TAGKEYS(XK_parenleft,10) TAGKEYS(XK_parenright,11) TAGKEYS(XK_BackSpace,12)
    { MODKEY|ShiftMask,             XK_e,      quit,           {0} },
};

static Button buttons[] = {
    { ClkRootWin,           NULL,           Button3,        spawn,          SHCMD("rcmen") },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};
