#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 41
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 25
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_V_LPAREN = 1,
  anon_sym_RPAREN_EQ_LBRACE = 2,
  anon_sym_COMMA = 3,
  anon_sym_RBRACE = 4,
  anon_sym_R = 5,
  anon_sym_EQ_LBRACE = 6,
  anon_sym_W_EQ_LBRACE = 7,
  anon_sym_LT = 8,
  anon_sym_GT = 9,
  anon_sym_w = 10,
  sym_atom = 11,
  sym_agent = 12,
  aux_sym_digit_token1 = 13,
  aux_sym_digit_token2 = 14,
  sym_statement = 15,
  sym_valuationset = 16,
  sym_relationset = 17,
  sym_worldset = 18,
  sym_relation = 19,
  sym_world = 20,
  sym_digit = 21,
  aux_sym_statement_repeat1 = 22,
  aux_sym_valuationset_repeat1 = 23,
  aux_sym_relationset_repeat1 = 24,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_V_LPAREN] = "V(",
  [anon_sym_RPAREN_EQ_LBRACE] = ")={",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACE] = "}",
  [anon_sym_R] = "R",
  [anon_sym_EQ_LBRACE] = "={",
  [anon_sym_W_EQ_LBRACE] = "W={",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_w] = "w",
  [sym_atom] = "atom",
  [sym_agent] = "agent",
  [aux_sym_digit_token1] = "digit_token1",
  [aux_sym_digit_token2] = "digit_token2",
  [sym_statement] = "statement",
  [sym_valuationset] = "valuationset",
  [sym_relationset] = "relationset",
  [sym_worldset] = "worldset",
  [sym_relation] = "relation",
  [sym_world] = "world",
  [sym_digit] = "digit",
  [aux_sym_statement_repeat1] = "statement_repeat1",
  [aux_sym_valuationset_repeat1] = "valuationset_repeat1",
  [aux_sym_relationset_repeat1] = "relationset_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_V_LPAREN] = anon_sym_V_LPAREN,
  [anon_sym_RPAREN_EQ_LBRACE] = anon_sym_RPAREN_EQ_LBRACE,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_R] = anon_sym_R,
  [anon_sym_EQ_LBRACE] = anon_sym_EQ_LBRACE,
  [anon_sym_W_EQ_LBRACE] = anon_sym_W_EQ_LBRACE,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_w] = anon_sym_w,
  [sym_atom] = sym_atom,
  [sym_agent] = sym_agent,
  [aux_sym_digit_token1] = aux_sym_digit_token1,
  [aux_sym_digit_token2] = aux_sym_digit_token2,
  [sym_statement] = sym_statement,
  [sym_valuationset] = sym_valuationset,
  [sym_relationset] = sym_relationset,
  [sym_worldset] = sym_worldset,
  [sym_relation] = sym_relation,
  [sym_world] = sym_world,
  [sym_digit] = sym_digit,
  [aux_sym_statement_repeat1] = aux_sym_statement_repeat1,
  [aux_sym_valuationset_repeat1] = aux_sym_valuationset_repeat1,
  [aux_sym_relationset_repeat1] = aux_sym_relationset_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_V_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN_EQ_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_R] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_W_EQ_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_w] = {
    .visible = true,
    .named = false,
  },
  [sym_atom] = {
    .visible = true,
    .named = true,
  },
  [sym_agent] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_digit_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_digit_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_valuationset] = {
    .visible = true,
    .named = true,
  },
  [sym_relationset] = {
    .visible = true,
    .named = true,
  },
  [sym_worldset] = {
    .visible = true,
    .named = true,
  },
  [sym_relation] = {
    .visible = true,
    .named = true,
  },
  [sym_world] = {
    .visible = true,
    .named = true,
  },
  [sym_digit] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_valuationset_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_relationset_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(9);
      if (lookahead == ')') ADVANCE(2);
      if (lookahead == ',') ADVANCE(12);
      if (lookahead == '<') ADVANCE(17);
      if (lookahead == '=') ADVANCE(5);
      if (lookahead == '>') ADVANCE(18);
      if (lookahead == 'R') ADVANCE(14);
      if (lookahead == 'V') ADVANCE(1);
      if (lookahead == 'W') ADVANCE(3);
      if (lookahead == 'w') ADVANCE(19);
      if (lookahead == '}') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('a' <= lookahead && lookahead <= 'd')) ADVANCE(21);
      if (('p' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      END_STATE();
    case 1:
      if (lookahead == '(') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == '=') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == '=') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == 'w') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      END_STATE();
    case 5:
      if (lookahead == '{') ADVANCE(15);
      END_STATE();
    case 6:
      if (lookahead == '{') ADVANCE(11);
      END_STATE();
    case 7:
      if (lookahead == '{') ADVANCE(16);
      END_STATE();
    case 8:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('p' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_V_LPAREN);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_RPAREN_EQ_LBRACE);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_R);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_EQ_LBRACE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_W_EQ_LBRACE);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_w);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_atom);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_agent);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_digit_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_digit_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 4},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_V_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN_EQ_LBRACE] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_R] = ACTIONS(1),
    [anon_sym_EQ_LBRACE] = ACTIONS(1),
    [anon_sym_W_EQ_LBRACE] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_w] = ACTIONS(1),
    [sym_atom] = ACTIONS(1),
    [sym_agent] = ACTIONS(1),
    [aux_sym_digit_token1] = ACTIONS(1),
    [aux_sym_digit_token2] = ACTIONS(1),
  },
  [1] = {
    [sym_statement] = STATE(37),
    [sym_valuationset] = STATE(2),
    [sym_relationset] = STATE(2),
    [sym_worldset] = STATE(2),
    [aux_sym_statement_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_V_LPAREN] = ACTIONS(5),
    [anon_sym_R] = ACTIONS(7),
    [anon_sym_W_EQ_LBRACE] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(5), 1,
      anon_sym_V_LPAREN,
    ACTIONS(7), 1,
      anon_sym_R,
    ACTIONS(9), 1,
      anon_sym_W_EQ_LBRACE,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    STATE(3), 4,
      sym_valuationset,
      sym_relationset,
      sym_worldset,
      aux_sym_statement_repeat1,
  [19] = 5,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 1,
      anon_sym_V_LPAREN,
    ACTIONS(18), 1,
      anon_sym_R,
    ACTIONS(21), 1,
      anon_sym_W_EQ_LBRACE,
    STATE(3), 4,
      sym_valuationset,
      sym_relationset,
      sym_worldset,
      aux_sym_statement_repeat1,
  [38] = 1,
    ACTIONS(24), 4,
      ts_builtin_sym_end,
      anon_sym_V_LPAREN,
      anon_sym_R,
      anon_sym_W_EQ_LBRACE,
  [45] = 1,
    ACTIONS(26), 4,
      ts_builtin_sym_end,
      anon_sym_V_LPAREN,
      anon_sym_R,
      anon_sym_W_EQ_LBRACE,
  [52] = 1,
    ACTIONS(28), 4,
      ts_builtin_sym_end,
      anon_sym_V_LPAREN,
      anon_sym_R,
      anon_sym_W_EQ_LBRACE,
  [59] = 1,
    ACTIONS(30), 4,
      ts_builtin_sym_end,
      anon_sym_V_LPAREN,
      anon_sym_R,
      anon_sym_W_EQ_LBRACE,
  [66] = 1,
    ACTIONS(32), 4,
      ts_builtin_sym_end,
      anon_sym_V_LPAREN,
      anon_sym_R,
      anon_sym_W_EQ_LBRACE,
  [73] = 1,
    ACTIONS(34), 4,
      ts_builtin_sym_end,
      anon_sym_V_LPAREN,
      anon_sym_R,
      anon_sym_W_EQ_LBRACE,
  [80] = 3,
    ACTIONS(36), 1,
      anon_sym_LT,
    STATE(10), 1,
      aux_sym_relationset_repeat1,
    STATE(39), 1,
      sym_relation,
  [90] = 3,
    ACTIONS(39), 1,
      anon_sym_w,
    STATE(20), 1,
      aux_sym_valuationset_repeat1,
    STATE(25), 1,
      sym_world,
  [100] = 3,
    ACTIONS(39), 1,
      anon_sym_w,
    STATE(11), 1,
      aux_sym_valuationset_repeat1,
    STATE(21), 1,
      sym_world,
  [110] = 3,
    ACTIONS(39), 1,
      anon_sym_w,
    STATE(18), 1,
      aux_sym_valuationset_repeat1,
    STATE(22), 1,
      sym_world,
  [120] = 3,
    ACTIONS(41), 1,
      anon_sym_LT,
    STATE(19), 1,
      aux_sym_relationset_repeat1,
    STATE(24), 1,
      sym_relation,
  [130] = 1,
    ACTIONS(43), 3,
      anon_sym_COMMA,
      anon_sym_RBRACE,
      anon_sym_GT,
  [136] = 1,
    ACTIONS(45), 3,
      anon_sym_COMMA,
      anon_sym_RBRACE,
      anon_sym_GT,
  [142] = 2,
    STATE(16), 1,
      sym_digit,
    ACTIONS(47), 2,
      aux_sym_digit_token1,
      aux_sym_digit_token2,
  [150] = 3,
    ACTIONS(39), 1,
      anon_sym_w,
    STATE(20), 1,
      aux_sym_valuationset_repeat1,
    STATE(26), 1,
      sym_world,
  [160] = 3,
    ACTIONS(41), 1,
      anon_sym_LT,
    STATE(10), 1,
      aux_sym_relationset_repeat1,
    STATE(27), 1,
      sym_relation,
  [170] = 3,
    ACTIONS(49), 1,
      anon_sym_w,
    STATE(20), 1,
      aux_sym_valuationset_repeat1,
    STATE(31), 1,
      sym_world,
  [180] = 2,
    ACTIONS(52), 1,
      anon_sym_COMMA,
    ACTIONS(54), 1,
      anon_sym_RBRACE,
  [187] = 2,
    ACTIONS(52), 1,
      anon_sym_COMMA,
    ACTIONS(56), 1,
      anon_sym_RBRACE,
  [194] = 2,
    ACTIONS(39), 1,
      anon_sym_w,
    STATE(33), 1,
      sym_world,
  [201] = 2,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
  [208] = 2,
    ACTIONS(52), 1,
      anon_sym_COMMA,
    ACTIONS(62), 1,
      anon_sym_RBRACE,
  [215] = 2,
    ACTIONS(52), 1,
      anon_sym_COMMA,
    ACTIONS(64), 1,
      anon_sym_RBRACE,
  [222] = 2,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    ACTIONS(66), 1,
      anon_sym_RBRACE,
  [229] = 2,
    ACTIONS(39), 1,
      anon_sym_w,
    STATE(40), 1,
      sym_world,
  [236] = 1,
    ACTIONS(68), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [241] = 1,
    ACTIONS(70), 1,
      sym_atom,
  [245] = 1,
    ACTIONS(52), 1,
      anon_sym_COMMA,
  [249] = 1,
    ACTIONS(72), 1,
      anon_sym_w,
  [253] = 1,
    ACTIONS(74), 1,
      anon_sym_COMMA,
  [257] = 1,
    ACTIONS(76), 1,
      anon_sym_LT,
  [261] = 1,
    ACTIONS(78), 1,
      anon_sym_EQ_LBRACE,
  [265] = 1,
    ACTIONS(80), 1,
      anon_sym_RPAREN_EQ_LBRACE,
  [269] = 1,
    ACTIONS(82), 1,
      ts_builtin_sym_end,
  [273] = 1,
    ACTIONS(84), 1,
      sym_agent,
  [277] = 1,
    ACTIONS(58), 1,
      anon_sym_COMMA,
  [281] = 1,
    ACTIONS(86), 1,
      anon_sym_GT,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 19,
  [SMALL_STATE(4)] = 38,
  [SMALL_STATE(5)] = 45,
  [SMALL_STATE(6)] = 52,
  [SMALL_STATE(7)] = 59,
  [SMALL_STATE(8)] = 66,
  [SMALL_STATE(9)] = 73,
  [SMALL_STATE(10)] = 80,
  [SMALL_STATE(11)] = 90,
  [SMALL_STATE(12)] = 100,
  [SMALL_STATE(13)] = 110,
  [SMALL_STATE(14)] = 120,
  [SMALL_STATE(15)] = 130,
  [SMALL_STATE(16)] = 136,
  [SMALL_STATE(17)] = 142,
  [SMALL_STATE(18)] = 150,
  [SMALL_STATE(19)] = 160,
  [SMALL_STATE(20)] = 170,
  [SMALL_STATE(21)] = 180,
  [SMALL_STATE(22)] = 187,
  [SMALL_STATE(23)] = 194,
  [SMALL_STATE(24)] = 201,
  [SMALL_STATE(25)] = 208,
  [SMALL_STATE(26)] = 215,
  [SMALL_STATE(27)] = 222,
  [SMALL_STATE(28)] = 229,
  [SMALL_STATE(29)] = 236,
  [SMALL_STATE(30)] = 241,
  [SMALL_STATE(31)] = 245,
  [SMALL_STATE(32)] = 249,
  [SMALL_STATE(33)] = 253,
  [SMALL_STATE(34)] = 257,
  [SMALL_STATE(35)] = 261,
  [SMALL_STATE(36)] = 265,
  [SMALL_STATE(37)] = 269,
  [SMALL_STATE(38)] = 273,
  [SMALL_STATE(39)] = 277,
  [SMALL_STATE(40)] = 281,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_statement_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat1, 2), SHIFT_REPEAT(30),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat1, 2), SHIFT_REPEAT(38),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_statement_repeat1, 2), SHIFT_REPEAT(12),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationset, 6),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_valuationset, 6),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_worldset, 3),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_worldset, 4),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationset, 5),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_valuationset, 5),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_relationset_repeat1, 2), SHIFT_REPEAT(23),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_digit, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_world, 2),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_valuationset_repeat1, 2), SHIFT_REPEAT(17),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relation, 5),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_valuationset_repeat1, 2),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_relationset_repeat1, 2),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [82] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_set(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
