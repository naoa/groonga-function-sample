#include <string.h>
#include <stdlib.h>
#include <groonga/plugin.h>

#ifdef __GNUC__
# define GNUC_UNUSED __attribute__((__unused__))
#else
# define GNUC_UNUSED
#endif

static grn_obj *
func_strlen(grn_ctx *ctx, GNUC_UNUSED int nargs, GNUC_UNUSED grn_obj **args,
                  grn_user_data *user_data)
{
  grn_obj *result;
  unsigned int str_length = GRN_TEXT_LEN(args[0]);

  if ((result = grn_plugin_proc_alloc(ctx, user_data, GRN_DB_INT64, 0))) {
    GRN_INT64_SET(ctx, result, str_length);
  }
  return result;
}

grn_rc
GRN_PLUGIN_INIT(GNUC_UNUSED grn_ctx *ctx)
{
  return GRN_SUCCESS;
}

grn_rc
GRN_PLUGIN_REGISTER(grn_ctx *ctx)
{
  grn_proc_create(ctx, "strlen", -1, GRN_PROC_FUNCTION,
                  func_strlen, NULL, NULL, 0, NULL);

  return ctx->rc;
}

grn_rc
GRN_PLUGIN_FIN(GNUC_UNUSED grn_ctx *ctx)
{
  return GRN_SUCCESS;
}
