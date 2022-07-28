/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;
static const unsigned int snap      = 32;
static const int showbar            = 0;
static const int topbar             = 1;
static const char *fonts[]          = { "Martian Mono Std Rg:pixelsize=16" };
static const char dmenufont[]       =   "Martian Mono Std Rg:pixelsize=16";
static const char col_black[]       = "#000000";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_ng1[]         = "#504945";
static const char col_gray3[]       = "#777777";
static const char col_red[]         = "#ff0000";
static const char col_green[]       = "#00875f";
static const char col_cyan[]        = "#005577";
static const char col_yellow[]      = "#ffff00";
static const char col_orange[]      = "#fe8019";

static const char *colors[][3]      = {
	/*                 fg          bg         border   */
	[SchemeNorm]   = { col_ng1,    col_black, col_gray1 },
	[SchemeSel]    = { col_gray3,  col_black, col_gray2 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50;
static const int nmaster     = 1;
static const int resizehints = 0;
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const Layout layouts[] = { { "", tile } };

/* key definitions */
#define MODKEY Mod1Mask
#define ALT Mod1Mask
#define META Mod4Mask
#define CTL ControlMask
#define SHIFT ShiftMask
#define TAGKEYS(KEY,TAG) \
	{ ALT,           KEY,      view,           {.ui = 1 << TAG} }, \
	{ ALT|CTL,       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ ALT|SHIFT,     KEY,      tag,            {.ui = 1 << TAG} }, \
	{ ALT|CTL|SHIFT, KEY,      toggletag,      {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define SCRIPTS "/home/hassan/.scripts/"

/* commands */
static char dmenumon[2] = "0";
static const char *dmenucmd[]          = { "dmenu_run", "-m", dmenumon, NULL };
static const char *surf[]              = { "surf", NULL };
static const char *htop[]              = { "st", "htop", NULL };
static const char *neomutt[]           = { "st", "neomutt", NULL };
static const char *termcmd[]           = { "st", NULL };
static const char *sfm[]               = { "st", "sfm", NULL };
static const char *search[]            = { SCRIPTS "search", NULL };
static const char *passmenu[]          = { SCRIPTS "pass_manager", NULL };
static const char *record_screen[]     = { SCRIPTS "record_screen", NULL};

static const char *call_bluetooth[]    = { SCRIPTS "bluetooth_call", NULL };
static const char *bluetooth_connect[] = { SCRIPTS "bluetooth_connect", NULL };
static const char *rfkill[]            = { SCRIPTS "rfkill", NULL };

static const char *connect_server[]    = { SCRIPTS "connect_server", NULL };

static const char *mount_drive[]       = { SCRIPTS "mount_drives", NULL };
static const char *unmount_drive[]     = { SCRIPTS "unmount_drives", NULL };

static const char *notify_azan[]       = { SCRIPTS "notify_azan", NULL };
static const char *notify_cpu[]        = { SCRIPTS "notify_cpu", NULL };
static const char *notify_disks[]      = { SCRIPTS "notify_disks", NULL };
static const char *notify_gpu[]        = { SCRIPTS "notify_gpu", NULL };
static const char *notify_network[]    = { SCRIPTS "network", "notify", NULL };

static const char *mute[]              = { SCRIPTS "volume_control", "mute_t", NULL };
static const char *volume_down[]       = { SCRIPTS "volume_control", "dec", NULL };
static const char *volume_up[]         = { SCRIPTS "volume_control", "inc", NULL };

static const char *play_music[]        = { SCRIPTS "play_music", "start", NULL };
static const char *play_pause[]        = { SCRIPTS "play_music", "play-pause", NULL };
static const char *next_song[]         = { SCRIPTS "play_music", "next", NULL  };
static const char *prev_song[]         = { SCRIPTS "play_music", "previous", NULL  };

static Key keys[] = {
	{ ALT,           XK_p,      spawn,          {.v = dmenucmd } },

	{ ALT,           XK_r,      spawn,          {.v = htop } },
	{ ALT,           XK_m,      spawn,          {.v = neomutt} },
	{ ALT,           XK_Return, spawn,          {.v = termcmd } },
	{ ALT,           XK_v,      spawn,          {.v = sfm } },
	{ ALT,           XK_w,      spawn,          {.v = passmenu} },
	{ ALT,           XK_o,      spawn,          {.v = record_screen } },
	{ ALT,           XK_f,      spawn,          {.v = surf } },
	{ ALT,           XK_backslash,      spawn,          {.v = search } },

	{ ALT|META,      XK_g,      spawn,          {.v = call_bluetooth } },
	{ ALT|SHIFT,     XK_g,      spawn,          {.v = bluetooth_connect } },
	{ ALT|META,      XK_k,      spawn,          {.v = rfkill } },

	{ ALT,           XK_g,      spawn,          {.v = connect_server} },

	{ ALT,           XK_t,      spawn,          {.v = mount_drive } },
	{ ALT,           XK_s,      spawn,          {.v = unmount_drive } },

	{ ALT|META,      XK_a,      spawn,          {.v = notify_azan} },
	{ ALT|META,      XK_c,      spawn,          {.v = notify_cpu} },
	{ ALT|META,      XK_d,      spawn,          {.v = notify_disks} },
	{ ALT|META,      XK_x,      spawn,          {.v = notify_gpu} },
	{ ALT|META,      XK_z,      spawn,          {.v = notify_network} },

	{ ALT,           XK_F10,    spawn,          {.v = mute} },
	{ ALT,           XK_F12,    spawn,          {.v = volume_down} },
	{ ALT,           XK_F11,    spawn,          {.v = volume_up} },

	{ ALT|META,      XK_p,      spawn,          {.v = play_music } },
	{ ALT,           XK_F7,     spawn,          {.v = play_pause } },
	{ ALT,           XK_F9,     spawn,          {.v = next_song} },
	{ ALT,           XK_F8,     spawn,          {.v = prev_song} },

	{ ALT|META,      XK_l,      spawn,          SHCMD("pkill gpg-agent; slock") },
	{ ALT|META,      XK_e,      spawn,          SHCMD("notify-send 'Email' 'mbsync -a' && mbsync -a") },
	{ ALT,           XK_Tab,    view,           {0} },
	{ ALT,           XK_b,      togglebar,      {0} },
	{ ALT,           XK_q,      killclient,     {0} },
	{ ALT,           XK_j,      focusstack,     {.i = +1 } },
	{ ALT,           XK_k,      focusstack,     {.i = -1 } },
	{ ALT,           XK_h,      setmfact,       {.f = -0.01} },
	{ ALT,           XK_l,      setmfact,       {.f = +0.01} },
	{ ALT,           XK_comma,  focusmon,       {.i = -1 } },
	{ ALT,           XK_period, focusmon,       {.i = +1 } },
	{ ALT|SHIFT,     XK_period, tagmon,         {.i = +1 } },
	{ ALT|SHIFT,     XK_comma,  tagmon,         {.i = -1 } },
	//{ ALT|SHIFT,             XK_j,      movestack,      {.i = +1 } },
	//{ ALT|SHIFT,             XK_k,      movestack,      {.i = -1 } },
	{ ALT|SHIFT,     XK_Return, zoom,           {0} },
	{ ALT|SHIFT,     XK_q,      quit,           {0} },
	TAGKEYS(         XK_1,                       0)
	TAGKEYS(         XK_2,                       1)
	TAGKEYS(         XK_3,                       2)
	TAGKEYS(         XK_4,                       3)
	TAGKEYS(         XK_5,                       4)
	TAGKEYS(         XK_6,                       5)
	TAGKEYS(         XK_7,                       6)
	TAGKEYS(         XK_8,                       7)
	TAGKEYS(         XK_9,                       8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click         event mask button   function        argument */
	{ ClkLtSymbol,   0,         Button1, setlayout,      {0} },
	{ ClkLtSymbol,   0,         Button3, setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,   0,         Button2, zoom,           {0} },
	{ ClkStatusText, 0,         Button2, spawn,          {.v = termcmd } },
	{ ClkClientWin,  ALT,       Button1, movemouse,      {0} },
	{ ClkClientWin,  ALT,       Button2, togglefloating, {0} },
	{ ClkClientWin,  ALT,       Button3, resizemouse,    {0} },
	{ ClkTagBar,     0,         Button1, view,           {0} },
	{ ClkTagBar,     0,         Button3, toggleview,     {0} },
	{ ClkTagBar,     ALT,       Button1, tag,            {0} },
	{ ClkTagBar,     ALT,       Button3, toggletag,      {0} },
};
