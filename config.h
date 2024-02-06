/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;
static const unsigned int snap      = 32;
static const int showbar            = 0;
static const int topbar             = 1;
static const char *fonts[]          = { "Martian Mono:pixelsize=16" };
static const char dmenufont[]       =   "Martian Mono:pixelsize=16";
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
	{ META,           KEY,      view,           {.ui = 1 << TAG} }, \
	{ META|CTL,       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ META|SHIFT,     KEY,      tag,            {.ui = 1 << TAG} }, \
	{ META|CTL|SHIFT, KEY,      toggletag,      {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define SCRIPTS "/home/hassan/.scripts/exec/"

/* commands */
static char dmenumon[2] = "0";
static const char *dmenucmd[]          = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]           = { "st", NULL };
static const char *passmenu[]          = { SCRIPTS "pass_manager", NULL };

static const char *gpg[]               = { SCRIPTS "gpg", NULL };
static const char *bluetooth_connect[] = { SCRIPTS "bluetooth_connect", NULL };
static const char *rfkill[]            = { SCRIPTS "rfkill", NULL };

static const char *mount_drive[]       = { SCRIPTS "mount_drives", NULL };
static const char *unmount_drive[]     = { SCRIPTS "unmount_drives", NULL };

static const char *notify_azan[]       = { SCRIPTS "notify_azan", NULL };
static const char *notify_cpu[]        = { SCRIPTS "notify_cpu", NULL };
static const char *notify_disks[]      = { SCRIPTS "notify_disks", NULL };
static const char *notify_gpu[]        = { SCRIPTS "notify_gpu", NULL };
static const char *notify_network[]    = { SCRIPTS "network", "notify", NULL };
static const char *notify_myip[]    = { SCRIPTS "myip", NULL };

static const char *mute[]              = { SCRIPTS "volume_control", "mute_t", NULL };
static const char *volume_down[]       = { SCRIPTS "volume_control", "dec", NULL };
static const char *volume_up[]         = { SCRIPTS "volume_control", "inc", NULL };

static const char *play_music[]        = { SCRIPTS "play_music", "start", NULL };
static const char *play_pause[]        = { SCRIPTS "play_music", "play-pause", NULL };
static const char *next_song[]         = { SCRIPTS "play_music", "next", NULL  };
static const char *prev_song[]         = { SCRIPTS "play_music", "previous", NULL  };

static const char *screenrecord[]      = { SCRIPTS "record_screen", NULL};
static const char *screenshot[]        = { "scrot", "-s", NULL };

static Key keys[] = {
	{ META,           XK_space,  spawn,          {.v = dmenucmd } },

	{ META,           XK_Return, spawn,          {.v = termcmd } },
	{ META,           XK_F3,     spawn,          {.v = passmenu} },

	{ META,           XK_g,      spawn,          {.v = gpg } },
	{ META|SHIFT,     XK_g,      spawn,          {.v = bluetooth_connect } },
	{ META|ALT,       XK_k,      spawn,          {.v = rfkill } },

	{ META,           XK_F4,     spawn,          {.v = mount_drive } },
	{ META,           XK_F5,     spawn,          {.v = unmount_drive } },

	{ META|ALT,       XK_a,      spawn,          {.v = notify_azan} },
	{ META|ALT,       XK_c,      spawn,          {.v = notify_cpu} },
	{ META|ALT,       XK_d,      spawn,          {.v = notify_disks} },
	{ META|ALT,       XK_x,      spawn,          {.v = notify_gpu} },
	{ META|ALT,       XK_z,      spawn,          {.v = notify_network} },
	{ META|ALT,       XK_i,      spawn,          {.v = notify_myip} },

	{ META,           XK_F10,    spawn,          {.v = mute} },
	{ META,           XK_F12,    spawn,          {.v = volume_down} },
	{ META,           XK_F11,    spawn,          {.v = volume_up} },

	{ META|ALT,       XK_p,      spawn,          {.v = play_music } },
	{ META,           XK_F7,     spawn,          {.v = play_pause } },
	{ META,           XK_F9,     spawn,          {.v = next_song} },
	{ META,           XK_F8,     spawn,          {.v = prev_song} },

	{ META,           XK_F1,     spawn,          {.v = screenshot} },
	{ META,           XK_F2,     spawn,          {.v = screenrecord} },

	{ META|ALT,       XK_l,      spawn,          SHCMD("pkill gpg-agent; slock") },
	{ META|ALT,       XK_e,      spawn,          SHCMD("notify-send 'Email' 'mbsync -a' && mbsync -a") },
	{ META,           XK_Tab,    view,           {0} },
	{ META,           XK_b,      togglebar,      {0} },
	{ META,           XK_q,      killclient,     {0} },
	{ META|SHIFT,     XK_j,      focusstack,     {.i = +1 } },
	{ META|SHIFT,     XK_k,      focusstack,     {.i = -1 } },
	{ META,           XK_h,      setmfact,       {.f = -0.01} },
	{ META,           XK_l,      setmfact,       {.f = +0.01} },
	{ META,           XK_comma,  focusmon,       {.i = -1 } },
	{ META,           XK_period, focusmon,       {.i = +1 } },
	{ META|SHIFT,     XK_period, tagmon,         {.i = +1 } },
	{ META|SHIFT,     XK_comma,  tagmon,         {.i = -1 } },
	{ META|SHIFT,     XK_Return, zoom,           {0} },
	{ META|SHIFT,     XK_q,      quit,           {0} },
	TAGKEYS(          XK_1,                       0)
	TAGKEYS(          XK_2,                       1)
	TAGKEYS(          XK_3,                       2)
	TAGKEYS(          XK_4,                       3)
	TAGKEYS(          XK_5,                       4)
	TAGKEYS(          XK_6,                       5)
	TAGKEYS(          XK_7,                       6)
	TAGKEYS(          XK_8,                       7)
	TAGKEYS(          XK_9,                       8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click         event mask button   function        argument */
	{ ClkLtSymbol,   0,         Button1, setlayout,      {0} },
	{ ClkLtSymbol,   0,         Button3, setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,   0,         Button2, zoom,           {0} },
	{ ClkStatusText, 0,         Button2, spawn,          {.v = termcmd } },
	{ ClkClientWin,  META,      Button1, movemouse,      {0} },
	{ ClkClientWin,  META,      Button2, togglefloating, {0} },
	{ ClkClientWin,  META,      Button3, resizemouse,    {0} },
	{ ClkTagBar,     0,         Button1, view,           {0} },
	{ ClkTagBar,     0,         Button3, toggleview,     {0} },
	{ ClkTagBar,     META,      Button1, tag,            {0} },
	{ ClkTagBar,     META,      Button3, toggletag,      {0} },
};
