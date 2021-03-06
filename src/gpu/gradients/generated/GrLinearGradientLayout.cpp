/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrLinearGradientLayout.fp; do not modify.
 **************************************************************************************************/
#include "GrLinearGradientLayout.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLLinearGradientLayout : public GrGLSLFragmentProcessor {
public:
    GrGLSLLinearGradientLayout() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrLinearGradientLayout& _outer = args.fFp.cast<GrLinearGradientLayout>();
        (void)_outer;
        fragBuilder->codeAppendf(
                R"SkSL(half t = half(%s.x) + 9.9999997473787516e-06;
%s = half4(t, 1.0, 0.0, 0.0);
)SkSL",
                args.fSampleCoord, args.fOutputColor);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrLinearGradientLayout::onCreateGLSLInstance() const {
    return new GrGLSLLinearGradientLayout();
}
void GrLinearGradientLayout::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                   GrProcessorKeyBuilder* b) const {}
bool GrLinearGradientLayout::onIsEqual(const GrFragmentProcessor& other) const {
    const GrLinearGradientLayout& that = other.cast<GrLinearGradientLayout>();
    (void)that;
    return true;
}
bool GrLinearGradientLayout::usesExplicitReturn() const { return false; }
GrLinearGradientLayout::GrLinearGradientLayout(const GrLinearGradientLayout& src)
        : INHERITED(kGrLinearGradientLayout_ClassID, src.optimizationFlags()) {
    this->cloneAndRegisterAllChildProcessors(src);
    this->setUsesSampleCoordsDirectly();
}
std::unique_ptr<GrFragmentProcessor> GrLinearGradientLayout::clone() const {
    return std::make_unique<GrLinearGradientLayout>(*this);
}
#if GR_TEST_UTILS
SkString GrLinearGradientLayout::onDumpInfo() const { return SkString(); }
#endif
GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrLinearGradientLayout);
#if GR_TEST_UTILS
std::unique_ptr<GrFragmentProcessor> GrLinearGradientLayout::TestCreate(GrProcessorTestData* d) {
    SkScalar scale = GrGradientShader::RandomParams::kGradientScale;
    SkPoint points[] = {
            {d->fRandom->nextRangeScalar(0.0f, scale), d->fRandom->nextRangeScalar(0.0f, scale)},
            {d->fRandom->nextRangeScalar(0.0f, scale), d->fRandom->nextRangeScalar(0.0f, scale)}};

    GrGradientShader::RandomParams params(d->fRandom);
    auto shader = params.fUseColors4f
                          ? SkGradientShader::MakeLinear(points, params.fColors4f,
                                                         params.fColorSpace, params.fStops,
                                                         params.fColorCount, params.fTileMode)
                          : SkGradientShader::MakeLinear(points, params.fColors, params.fStops,
                                                         params.fColorCount, params.fTileMode);
    GrTest::TestAsFPArgs asFPArgs(d);
    std::unique_ptr<GrFragmentProcessor> fp = as_SB(shader)->asFragmentProcessor(asFPArgs.args());
    SkASSERT_RELEASE(fp);
    return fp;
}
#endif

std::unique_ptr<GrFragmentProcessor> GrLinearGradientLayout::Make(const SkLinearGradient& grad,
                                                                  const GrFPArgs& args) {
    SkMatrix matrix;
    if (!grad.totalLocalMatrix(args.fPreLocalMatrix)->invert(&matrix)) {
        return nullptr;
    }
    matrix.postConcat(grad.getGradientMatrix());
    return GrMatrixEffect::Make(matrix,
                                std::unique_ptr<GrFragmentProcessor>(new GrLinearGradientLayout()));
}
