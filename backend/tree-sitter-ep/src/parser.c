#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 27
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
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
  anon_sym_C = 9,
  anon_sym_LBRACE = 10,
  anon_sym_RBRACE = 11,
  sym_atom = 12,
  aux_sym_agent_token1 = 13,
  aux_sym_agent_token2 = 14,
  aux_sym_digit_token1 = 15,
  aux_sym_digit_token2 = 16,
  sym_formula = 17,
  sym__monary_expression = 18,
  sym__binary_expression = 19,
  sym__par_expression = 20,
  sym__monary_operator = 21,
  sym__binary_operator = 22,
  sym_know = 23,
  sym_common = 24,
  sym_agent = 25,
  aux_sym_common_repeat1 = 26,
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
      if (lookahead == 'C') ADVANCE(14);
      if (lookahead == 'K') ADVANCE(13);
      if (lookahead == '{') ADVANCE(15);
      if (lookahead == '|') ADVANCE(4);
      if (lookahead == '}') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('a' <= lookahead && lookahead <= 'd')) ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      if (('p' <= lookahead && lookahead <= 'z')) ADVANCE(17);
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
      ACCEPT_TOKEN(anon_sym_C);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_atom);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_agent_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_agent_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_digit_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_digit_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
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
    [sym_formula] = STATE(12),
    [sym__monary_expression] = STATE(11),
    [sym__binary_expression] = STATE(9),
    [sym__par_expression] = STATE(8),
    [sym__monary_operator] = STATE(2),
    [sym_know] = STATE(2),
    [sym_common] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(3),
    [sym_not] = ACTIONS(5),
    [anon_sym_K] = ACTIONS(7),
    [anon_sym_C] = ACTIONS(9),
    [sym_atom] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      sym_not,
    ACTIONS(7), 1,
      anon_sym_K,
    ACTIONS(9), 1,
      anon_sym_C,
    ACTIONS(11), 1,
      sym_atom,
    STATE(7), 1,
      sym_formula,
    STATE(8), 1,
      sym__par_expression,
    STATE(9), 1,
      sym__binary_expression,
    STATE(11), 1,
      sym__monary_expression,
    STATE(2), 3,
      sym__monary_operator,
      sym_know,
      sym_common,
  [33] = 10,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      sym_not,
    ACTIONS(7), 1,
      anon_sym_K,
    ACTIONS(9), 1,
      anon_sym_C,
    ACTIONS(11), 1,
      sym_atom,
    STATE(8), 1,
      sym__par_expression,
    STATE(9), 1,
      sym__binary_expression,
    STATE(10), 1,
      sym_formula,
    STATE(11), 1,
      sym__monary_expression,
    STATE(2), 3,
      sym__monary_operator,
      sym_know,
      sym_common,
  [66] = 10,
    ACTIONS(3), 1,
      anon_sym_LPAREN,
    ACTIONS(5), 1,
      sym_not,
    ACTIONS(7), 1,
      anon_sym_K,
    ACTIONS(9), 1,
      anon_sym_C,
    ACTIONS(11), 1,
      sym_atom,
    STATE(6), 1,
      sym_formula,
    STATE(8), 1,
      sym__par_expression,
    STATE(9), 1,
      sym__binary_expression,
    STATE(11), 1,
      sym__monary_expression,
    STATE(2), 3,
      sym__monary_operator,
      sym_know,
      sym_common,
  [99] = 2,
    ACTIONS(15), 1,
      aux_sym_agent_token1,
    ACTIONS(13), 7,
      anon_sym_LPAREN,
      sym_not,
      anon_sym_K,
      anon_sym_C,
      anon_sym_RBRACE,
      sym_atom,
      aux_sym_agent_token2,
  [112] = 2,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(17), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [124] = 2,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(19), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [136] = 1,
    ACTIONS(21), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [145] = 1,
    ACTIONS(23), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [154] = 3,
    ACTIONS(25), 1,
      anon_sym_RPAREN,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(27), 4,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [167] = 1,
    ACTIONS(29), 6,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      sym_and,
      sym_iff,
      sym_eq,
      sym_or,
  [176] = 3,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym__binary_operator,
    ACTIONS(27), 4,
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
  [198] = 1,
    ACTIONS(35), 5,
      anon_sym_LPAREN,
      sym_not,
      anon_sym_K,
      anon_sym_C,
      sym_atom,
  [206] = 4,
    ACTIONS(37), 1,
      anon_sym_RBRACE,
    ACTIONS(39), 1,
      aux_sym_agent_token1,
    ACTIONS(41), 1,
      aux_sym_agent_token2,
    STATE(17), 2,
      sym_agent,
      aux_sym_common_repeat1,
  [220] = 1,
    ACTIONS(43), 5,
      anon_sym_LPAREN,
      sym_not,
      anon_sym_K,
      anon_sym_C,
      sym_atom,
  [228] = 4,
    ACTIONS(45), 1,
      anon_sym_RBRACE,
    ACTIONS(47), 1,
      aux_sym_agent_token1,
    ACTIONS(50), 1,
      aux_sym_agent_token2,
    STATE(17), 2,
      sym_agent,
      aux_sym_common_repeat1,
  [242] = 3,
    ACTIONS(39), 1,
      aux_sym_agent_token1,
    ACTIONS(41), 1,
      aux_sym_agent_token2,
    STATE(15), 2,
      sym_agent,
      aux_sym_common_repeat1,
  [253] = 3,
    ACTIONS(39), 1,
      aux_sym_agent_token1,
    ACTIONS(41), 1,
      aux_sym_agent_token2,
    STATE(14), 1,
      sym_agent,
  [263] = 1,
    ACTIONS(53), 1,
      anon_sym_LBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 33,
  [SMALL_STATE(4)] = 66,
  [SMALL_STATE(5)] = 99,
  [SMALL_STATE(6)] = 112,
  [SMALL_STATE(7)] = 124,
  [SMALL_STATE(8)] = 136,
  [SMALL_STATE(9)] = 145,
  [SMALL_STATE(10)] = 154,
  [SMALL_STATE(11)] = 167,
  [SMALL_STATE(12)] = 176,
  [SMALL_STATE(13)] = 189,
  [SMALL_STATE(14)] = 198,
  [SMALL_STATE(15)] = 206,
  [SMALL_STATE(16)] = 220,
  [SMALL_STATE(17)] = 228,
  [SMALL_STATE(18)] = 242,
  [SMALL_STATE(19)] = 253,
  [SMALL_STATE(20)] = 263,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_agent, 1),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_agent, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__binary_expression, 3, .production_id = 4),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__monary_expression, 2, .production_id = 3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1, .production_id = 2),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1, .production_id = 1),
  [31] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__par_expression, 3),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_know, 2),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_common, 4),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_common_repeat1, 2),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_common_repeat1, 2), SHIFT_REPEAT(5),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_common_repeat1, 2), SHIFT_REPEAT(5),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
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
