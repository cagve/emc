#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 23
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 29
#define ALIAS_COUNT 0
#define TOKEN_COUNT 18
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 5

enum {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  sym_not = 3,
  sym_and = 4,
  sym_iff = 5,
  sym_eq = 6,
  sym_or = 7,
  anon_sym_K = 8,
  anon_sym_M = 9,
  anon_sym_C = 10,
  anon_sym_LBRACE = 11,
  anon_sym_RBRACE = 12,
  sym_atom = 13,
  aux_sym_agent_token1 = 14,
  aux_sym_agent_token2 = 15,
  aux_sym_digit_token1 = 16,
  aux_sym_digit_token2 = 17,
  sym_formula = 18,
  sym__monary_expression = 19,
  sym__binary_expression = 20,
  sym__par_expression = 21,
  sym__monary_operator = 22,
  sym__binary_operator = 23,
  sym_know = 24,
  sym_pos = 25,
  sym_common = 26,
  sym_agent = 27,
  aux_sym_common_repeat1 = 28,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_not] = "not",
  [sym_and] = "and",
  [sym_iff] = "iff",
  [sym_eq] = "eq",
  [sym_or] = "or",
  [anon_sym_K] = "K",
  [anon_sym_M] = "M",
  [anon_sym_C] = "C",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_atom] = "atom",
  [aux_sym_agent_token1] = "agent_token1",
  [aux_sym_agent_token2] = "agent_token2",
  [aux_sym_digit_token1] = "digit_token1",
  [aux_sym_digit_token2] = "digit_token2",
  [sym_formula] = "formula",
  [sym__monary_expression] = "_monary_expression",
  [sym__binary_expression] = "_binary_expression",
  [sym__par_expression] = "_par_expression",
  [sym__monary_operator] = "_monary_operator",
  [sym__binary_operator] = "_binary_operator",
  [sym_know] = "know",
  [sym_pos] = "pos",
  [sym_common] = "common",
  [sym_agent] = "agent",
  [aux_sym_common_repeat1] = "common_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_not] = sym_not,
  [sym_and] = sym_and,
  [sym_iff] = sym_iff,
  [sym_eq] = sym_eq,
  [sym_or] = sym_or,
  [anon_sym_K] = anon_sym_K,
  [anon_sym_M] = anon_sym_M,
  [anon_sym_C] = anon_sym_C,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_atom] = sym_atom,
  [aux_sym_agent_token1] = aux_sym_agent_token1,
  [aux_sym_agent_token2] = aux_sym_agent_token2,
  [aux_sym_digit_token1] = aux_sym_digit_token1,
  [aux_sym_digit_token2] = aux_sym_digit_token2,
  [sym_formula] = sym_formula,
  [sym__monary_expression] = sym__monary_expression,
  [sym__binary_expression] = sym__binary_expression,
  [sym__par_expression] = sym__par_expression,
  [sym__monary_operator] = sym__monary_operator,
  [sym__binary_operator] = sym__binary_operator,
  [sym_know] = sym_know,
  [sym_pos] = sym_pos,
  [sym_common] = sym_common,
  [sym_agent] = sym_agent,
  [aux_sym_common_repeat1] = aux_sym_common_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_not] = {
    .visible = true,
    .named = true,
  },
  [sym_and] = {
    .visible = true,
    .named = true,
  },
  [sym_iff] = {
    .visible = true,
    .named = true,
  },
  [sym_eq] = {
    .visible = true,
    .named = true,
  },
  [sym_or] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_K] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_M] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_C] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_atom] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_agent_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_agent_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_digit_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_digit_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_formula] = {
    .visible = true,
    .named = true,
  },
  [sym__monary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym__binary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym__par_expression] = {
    .visible = false,
    .named = true,
  },
  [sym__monary_operator] = {
    .visible = false,
    .named = true,
  },
  [sym__binary_operator] = {
    .visible = false,
    .named = true,
  },
  [sym_know] = {
    .visible = true,
    .named = true,
  },
  [sym_pos] = {
    .visible = true,
    .named = true,
  },
  [sym_common] = {
    .visible = true,
    .named = true,
  },
  [sym_agent] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_common_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_left_term = 1,
  field_operator = 2,
  field_right_term = 3,
  field_term = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_left_term] = "left_term",
  [field_operator] = "operator",
  [field_right_term] = "right_term",
  [field_term] = "term",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 3},
  [3] = {.index = 5, .length = 2},
  [4] = {.index = 7, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_operator, 0, .inherited = true},
    {field_term, 0, .inherited = true},
  [2] =
    {field_left_term, 0, .inherited = true},
    {field_operator, 0, .inherited = true},
    {field_right_term, 0, .inherited = true},
  [5] =
    {field_operator, 0},
    {field_term, 1},
  [7] =
    {field_left_term, 0},
    {field_operator, 1},
    {field_right_term, 2},
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
      if (eof) ADVANCE(5);
      if (lookahead == '&') ADVANCE(1);
      if (lookahead == '(') ADVANCE(6);
      if (lookahead == ')') ADVANCE(7);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == '=') ADVANCE(3);
      if (lookahead == 'C') ADVANCE(15);
      if (lookahead == 'K') ADVANCE(13);
      if (lookahead == 'M') ADVANCE(14);
      if (lookahead == '{') ADVANCE(16);
      if (lookahead == '|') ADVANCE(4);
      if (lookahead == '}') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('a' <= lookahead && lookahead <= 'd')) ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      if (('p' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 1:
      if (lookahead == '&') ADVANCE(9);
      END_STATE();
    case 2:
      if (lookahead == '>') ADVANCE(11);
      END_STATE();
    case 3:
      if (lookahead == '>') ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == '|') ADVANCE(12);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_not);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_and);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_iff);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_eq);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_or);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_K);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_M);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_C);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_atom);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_agent_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_agent_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_digit_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_digit_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(22);
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
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_not] = ACTIONS(1),
    [sym_and] = ACTIONS(1),
    [sym_iff] = ACTIONS(1),
    [sym_eq] = ACTIONS(1),
    [sym_or] = ACTIONS(1),
    [anon_sym_K] = ACTIONS(1),
    [anon_sym_M] = ACTIONS(1),
    [anon_sym_C] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_atom] = ACTIONS(1),
    [aux_sym_agent_token1] = ACTIONS(1),
    [aux_sym_agent_token2] = ACTIONS(1),
    [aux_sym_digit_token1] = ACTIONS(1),
    [aux_sym_digit_token2] = ACTIONS(1),
  },
  [1] = {
    [sym_formula] = STATE(10),
    [sym__monary_expression] = STATE(11),
    [sym__binary_expression] = STATE(12),
    [sym__par_expression] = STATE(9),
    [sym__monary_operator] = STATE(3),
    [sym_know] = STATE(3),
    [sym_pos] = STATE(3),
    [sym_common] = STATE(3),
    [anon_sym_LPAREN] = ACTIONS(3),
    [sym_not] = ACTIONS(5),
    [anon_sym_K] = ACTIONS(7),
    [anon_sym_M] = ACTIONS(9),
    [anon_sym_C] = ACTIONS(11),
    [sym_atom] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      sym_not,
    ACTIONS(7), 1,
      anon_sym_K,
    ACTIONS(9), 1,
      anon_sym_M,
    ACTIONS(11), 1,
      anon_sym_C,
    ACTIONS(13), 1,
      sym_atom,
    STATE(9), 1,
      sym__par_expression,
    STATE(11), 1,
      sym__monary_expression,
    STATE(12), 1,
      sym__binary_expression,
    STATE(13), 1,
      sym_formula,
    STATE(3), 4,
      sym__monary_operator,
      sym_know,
      sym_pos,
      sym_common,
  [37] = 11,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      sym_not,
    ACTIONS(7), 1,
      anon_sym_K,
    ACTIONS(9), 1,
      anon_sym_M,
    ACTIONS(11), 1,
      anon_sym_C,
    ACTIONS(13), 1,
      sym_atom,
    STATE(7), 1,
      sym_formula,
    STATE(9), 1,
      sym__par_expression,
    STATE(11), 1,
      sym__monary_expression,
    STATE(12), 1,
      sym__binary_expression,
    STATE(3), 4,
      sym__monary_operator,
      sym_know,
      sym_pos,
      sym_common,
  [74] = 11,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      sym_not,
    ACTIONS(7), 1,
      anon_sym_K,
    ACTIONS(9), 1,
      anon_sym_M,
    ACTIONS(11), 1,
      anon_sym_C,
    ACTIONS(13), 1,
      sym_atom,
    STATE(6), 1,
      sym_formula,
    STATE(9), 1,
      sym__par_expression,
    STATE(11), 1,
      sym__monary_expression,
    STATE(12), 1,
      sym__binary_expression,
    STATE(3), 4,
      sym__monary_operator,
      sym_know,
      sym_pos,
      sym_common,
  [111] = 2,
    ACTIONS(17), 1,
      aux_sym_agent_token1,
    ACTIONS(15), 8,
      anon_sym_LPAREN,
      sym_not,
      anon_sym_K,
      anon_sym_M,
      anon_sym_C,
      anon_sym_RBRACE,
      sym_atom,
      aux_sym_agent_token2,
  [125] = 2,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(19), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [137] = 2,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(21), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [149] = 1,
    ACTIONS(23), 6,
      anon_sym_LPAREN,
      sym_not,
      anon_sym_K,
      anon_sym_M,
      anon_sym_C,
      sym_atom,
  [158] = 1,
    ACTIONS(25), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [167] = 3,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(29), 4,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [180] = 1,
    ACTIONS(31), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [189] = 1,
    ACTIONS(33), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [198] = 3,
    ACTIONS(35), 1,
      anon_sym_RPAREN,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(29), 4,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [211] = 1,
    ACTIONS(37), 6,
      anon_sym_LPAREN,
      sym_not,
      anon_sym_K,
      anon_sym_M,
      anon_sym_C,
      sym_atom,
  [220] = 1,
    ACTIONS(39), 6,
      anon_sym_LPAREN,
      sym_not,
      anon_sym_K,
      anon_sym_M,
      anon_sym_C,
      sym_atom,
  [229] = 1,
    ACTIONS(41), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [238] = 4,
    ACTIONS(43), 1,
      anon_sym_RBRACE,
    ACTIONS(45), 1,
      aux_sym_agent_token1,
    ACTIONS(47), 1,
      aux_sym_agent_token2,
    STATE(18), 2,
      sym_agent,
      aux_sym_common_repeat1,
  [252] = 4,
    ACTIONS(49), 1,
      anon_sym_RBRACE,
    ACTIONS(51), 1,
      aux_sym_agent_token1,
    ACTIONS(54), 1,
      aux_sym_agent_token2,
    STATE(18), 2,
      sym_agent,
      aux_sym_common_repeat1,
  [266] = 3,
    ACTIONS(45), 1,
      aux_sym_agent_token1,
    ACTIONS(47), 1,
      aux_sym_agent_token2,
    STATE(17), 2,
      sym_agent,
      aux_sym_common_repeat1,
  [277] = 3,
    ACTIONS(45), 1,
      aux_sym_agent_token1,
    ACTIONS(47), 1,
      aux_sym_agent_token2,
    STATE(14), 1,
      sym_agent,
  [287] = 3,
    ACTIONS(45), 1,
      aux_sym_agent_token1,
    ACTIONS(47), 1,
      aux_sym_agent_token2,
    STATE(15), 1,
      sym_agent,
  [297] = 1,
    ACTIONS(57), 1,
      anon_sym_LBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 37,
  [SMALL_STATE(4)] = 74,
  [SMALL_STATE(5)] = 111,
  [SMALL_STATE(6)] = 125,
  [SMALL_STATE(7)] = 137,
  [SMALL_STATE(8)] = 149,
  [SMALL_STATE(9)] = 158,
  [SMALL_STATE(10)] = 167,
  [SMALL_STATE(11)] = 180,
  [SMALL_STATE(12)] = 189,
  [SMALL_STATE(13)] = 198,
  [SMALL_STATE(14)] = 211,
  [SMALL_STATE(15)] = 220,
  [SMALL_STATE(16)] = 229,
  [SMALL_STATE(17)] = 238,
  [SMALL_STATE(18)] = 252,
  [SMALL_STATE(19)] = 266,
  [SMALL_STATE(20)] = 277,
  [SMALL_STATE(21)] = 287,
  [SMALL_STATE(22)] = 297,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_agent, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_agent, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__binary_expression, 3, .production_id = 4),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__monary_expression, 2, .production_id = 3),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_common, 4),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1),
  [27] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1, .production_id = 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1, .production_id = 2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_know, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pos, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__par_expression, 3),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_common_repeat1, 2),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_common_repeat1, 2), SHIFT_REPEAT(5),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_common_repeat1, 2), SHIFT_REPEAT(5),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ep(void) {
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
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
