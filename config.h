/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;
static const unsigned int snap      = 32;
static const int showbar            = 0;
static const int topbar             = 1;
static const char *fonts[]          = { "Terminus:pixelsize=22" };
static const char dmenufont[]       =   "Terminus:pixelsize=22";
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
	[SchemeRed]    = { col_red,    col_black, col_black },
	[SchemeGreen]  = { col_green,  col_black, col_black },
	[SchemeCyan]   = { col_cyan,   col_black, col_black },
	[SchemeYellow] = { col_yellow, col_black, col_black },
	[SchemeOrange] = { col_orange, col_black, col_black },
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
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define SCRIPTS "/home/hassan/.scripts/"

/* commands */
static char dmenumon[2] = "0";
static const char *bright_inc[]        = { "xbacklight", "-inc", "10", NULL };
static const char *bright_max[]        = { "xbacklight", "-set", "100", NULL };
static const char *bright_min[]        = { "xbacklight", "-set", "0", NULL };
static const char *dmenucmd[]          = { "dmenu_run", "-m", dmenumon, NULL };
static const char *redshift[]          = { "redshift", "-P", "-O", "3000", "-m", "randr", NULL };
static const char *redshift_r[]        = { "redshift", "-x", "-m", "randr", NULL };
static const char *htop[]              = { "st", "htop", NULL };
static const char *neomutt[]           = { "st", "neomutt", NULL };
static const char *termcmd[]           = { "st", NULL };
static const char *toxic[]             = { "st", "toxic", NULL };
static const char *sfm[]               = { "st", "sfm", NULL };
static const char *bright_dec[]        = { SCRIPTS "x_dec", NULL};
static const char *call_bluetooth[]    = { SCRIPTS "bluetooth_call", NULL };
static const char *connect_bluetooth[] = { SCRIPTS "bluetooth_connect", NULL };
static const char *connect_server[]    = { SCRIPTS "connect_server", NULL };
static const char *mount_drive[]       = { SCRIPTS "mount_drives", NULL };
static const char *mute[]              = { SCRIPTS "volume_control", "mute_t", NULL };
static const char *next_song[]         = { SCRIPTS "play_music", "next", NULL  };
static const char *notify_azan[]       = { SCRIPTS "notify_azan", NULL };
static const char *notify_cpu[]        = { SCRIPTS "notify_cpu", NULL };
static const char *notify_disks[]      = { SCRIPTS "notify_disks", NULL };
static const char *notify_gpu[]        = { SCRIPTS "notify_gpu", NULL };
static const char *notify_network[]    = { SCRIPTS "network", "notify", NULL };
static const char *passmenu[]          = { SCRIPTS "pass_manager", NULL };
static const char *play_music[]        = { SCRIPTS "play_music", "choose", NULL };
static const char *play_pause[]        = { SCRIPTS "play_music", "play-pause", NULL };
static const char *prev_song[]         = { SCRIPTS "play_music", "previous", NULL  };
static const char *record_screen[]     = { SCRIPTS "record_screen", NULL};
static const char *run_my_scripts[]    = { SCRIPTS "list_scripts", NULL };
static const char *search[]            = { SCRIPTS "search", NULL };
static const char *surf_homepage[]     = { SCRIPTS "surf_homepage", NULL };
static const char *unmount_drive[]     = { SCRIPTS "unmount_drives", NULL };
static const char *update[]            = { SCRIPTS "update", NULL };
static const char *volume_down[]       = { SCRIPTS "volume_control", "dec", NULL };
static const char *volume_up[]         = { SCRIPTS "volume_control", "inc", NULL };

static Key keys[] = {
	{ ShiftMask,                    XK_F2,     spawn,          {.v = bright_max} },
	{ ShiftMask,                    XK_F1,     spawn,          {.v = bright_min} },
	{ MODKEY|ControlMask|Mod4Mask,  XK_b,      spawn,          {.v = call_bluetooth } },
	{ MODKEY|Mod4Mask,              XK_b,      spawn,          {.v = connect_bluetooth } },
	{ MODKEY|Mod4Mask,              XK_s,      spawn,          {.v = connect_server} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|Mod4Mask,              XK_h,      spawn,          {.v = htop } },
	{ MODKEY|Mod4Mask,              XK_m,      spawn,          {.v = mount_drive } },
	{ MODKEY,                       XK_m,      spawn,          {.v = neomutt} },
	{ MODKEY|Mod4Mask,              XK_a,      spawn,          {.v = notify_azan} },
	{ MODKEY|Mod4Mask,              XK_c,      spawn,          {.v = notify_cpu} },
	{ MODKEY|Mod4Mask,              XK_d,      spawn,          {.v = notify_disks} },
	{ MODKEY|Mod4Mask,              XK_g,      spawn,          {.v = notify_gpu} },
	{ MODKEY|Mod4Mask,              XK_n,      spawn,          {.v = notify_network} },
	{ MODKEY,                       XK_w,      spawn,          {.v = passmenu} },
	{ MODKEY|Mod4Mask,              XK_p,      spawn,          {.v = play_music } },
	{ MODKEY|ControlMask|Mod4Mask,  XK_o,      spawn,          {.v = record_screen } },
	{ MODKEY|Mod4Mask,              XK_r,      spawn,          {.v = redshift} },
	{ MODKEY|ShiftMask|Mod4Mask,    XK_r,      spawn,          {.v = redshift_r} },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = run_my_scripts} },
	{ MODKEY,                       XK_s,      spawn,          {.v = search} },
	{ MODKEY,                       XK_r,      spawn,          {.v = surf_homepage} },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_t,      spawn,          {.v = toxic } },
	{ MODKEY|ShiftMask|Mod4Mask,    XK_m,      spawn,          {.v = unmount_drive } },
	{ MODKEY|Mod4Mask,              XK_u,      spawn,          {.v = update} },
	{ MODKEY,                       XK_v,      spawn,          {.v = sfm } },
	{ MODKEY|Mod4Mask,              XK_l,      spawn,          SHCMD("pkill gpg-agent; slock& sleep 1 && xset dpms force off") },
	{ MODKEY|Mod4Mask,              XK_z,      spawn,          SHCMD("pkill gpg-agent; slock& doas zzz") },
	{ MODKEY|Mod4Mask,              XK_x,      spawn,          SHCMD("pkill xbanish;xbanish -m ne&") },
	{ 0,                            XK_F1,     spawn,          {.v = bright_dec} },
	{ 0,                            XK_F2,     spawn,          {.v = bright_inc} },
	{ 0,                            XK_F10,    spawn,          {.v = mute} },
	{ 0,                            XK_F9,     spawn,          {.v = next_song} },
	{ 0,                            XK_F7,     spawn,          {.v = play_pause } },
	{ 0,                            XK_F8,     spawn,          {.v = prev_song} },
	{ 0,                            XK_F11,    spawn,          {.v = volume_down} },
	{ 0,                            XK_F12,    spawn,          {.v = volume_up} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.01} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	//{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	//{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	TAGKEYS(                        XK_7,                       6)
	TAGKEYS(                        XK_8,                       7)
	TAGKEYS(                        XK_9,                       8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

